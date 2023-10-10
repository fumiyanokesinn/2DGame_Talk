extends Node2D

@onready var balloon: Panel = $Balloon
@onready var character_label: RichTextLabel = $Balloon/CharacterLabel
@onready var dialogue_label: DialogueLabel = $Balloon/DialogueLabel
@onready var responses_menu: DialogueResponsesMenu = $Balloon/ResponsesMenu

## The dialogue resource
var resource: DialogueResource

## Temporary game states
var temporary_game_states: Array = []

## See if we are waiting for the player
var is_waiting_for_input: bool = false

## See if we are running a long mutation and should hide the balloon
var will_hide_balloon: bool = false

## The current line
var dialogue_line: DialogueLine:
	set(next_dialogue_line):
		is_waiting_for_input = false

		# The dialogue has finished so close the balloon
		if not next_dialogue_line:
			queue_free()
			return

		dialogue_line = next_dialogue_line

		character_label.visible = not dialogue_line.character.is_empty()
		character_label.text = tr(dialogue_line.character, "dialogue")

		dialogue_label.hide()
		dialogue_label.dialogue_line = dialogue_line

		responses_menu.hide()
		responses_menu.set_responses(dialogue_line.responses)

		# Show our balloon
		balloon.show()
		will_hide_balloon = false

		dialogue_label.show()
		if not dialogue_line.text.is_empty():
			dialogue_label.type_out()
			await dialogue_label.finished_typing

		# Wait for input
		if dialogue_line.responses.size() > 0:
			balloon.focus_mode = Control.FOCUS_NONE
			responses_menu.show()
		elif dialogue_line.time != null:
			var time = dialogue_line.text.length() * 0.02 if dialogue_line.time == "auto" else dialogue_line.time.to_float()
			await get_tree().create_timer(time).timeout
			next(dialogue_line.next_id)
		else:
			is_waiting_for_input = true
			balloon.focus_mode = Control.FOCUS_ALL
			balloon.grab_focus()
	get:
		return dialogue_line

func _ready() -> void:
	balloon.hide()

## Start some dialogue
func start(dialogue_resource: DialogueResource, title: String, extra_game_states: Array = []) -> void:
	temporary_game_states = extra_game_states
	is_waiting_for_input = false
	resource = dialogue_resource
	self.dialogue_line = await resource.get_next_dialogue_line(title, temporary_game_states)

## Go to the next line
func next(next_id: String) -> void:
	self.dialogue_line = await resource.get_next_dialogue_line(next_id, temporary_game_states)



func _on_balloon_gui_input(event: InputEvent) -> void:
	# If the user clicks on the balloon while it's typing then skip typing
	if dialogue_label.is_typing and event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_LEFT and event.is_pressed():
		get_viewport().set_input_as_handled()
		dialogue_label.skip_typing()
		return

	if not is_waiting_for_input: return
	if dialogue_line.responses.size() > 0: return

	# When there are no response options the balloon itself is the clickable thing
	get_viewport().set_input_as_handled()

	if event is InputEventMouseButton and event.is_pressed() and event.button_index == 1:
		next(dialogue_line.next_id)
	elif event.is_action_pressed("ui_accept") and get_viewport().gui_get_focus_owner() == balloon:
		next(dialogue_line.next_id)

