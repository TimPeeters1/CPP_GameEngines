#include "player.h"


using namespace godot;


void Player::_register_methods()
{
  register_method("_process", &Player::_process);
}

Player::Player()
{
}

Player::~Player()
{
  // Some cleanup here?
}

void Player::_init()
{
}

void Player::_process(float delta)
{
  Input *input = Input::get_singleton();
  if (input->is_action_pressed("Player_Right"))
  {
    RigidBody::add_force(Vector3(-MovementSpeed,0,0), get_transform().origin);
  }

  if (input->is_action_pressed("Player_Left"))
  {
    RigidBody::add_force(Vector3(MovementSpeed,0,0), get_transform().origin);
  }
}

void Player::_input(Variant event)
{
}
