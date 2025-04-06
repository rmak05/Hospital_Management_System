#pragma once

enum class SceneId;
enum class EntityType;

enum class SceneId {
	_default			= (-1),
	login				= 0,
	frontdesk_login		= 1
};

enum class EntityType {
	_default			= (-1),
	text_box			= 0,
	button				= 1,
	image_box			= 2,
	text_input			= 3
};