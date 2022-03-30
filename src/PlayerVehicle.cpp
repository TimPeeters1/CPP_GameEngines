#include "PlayerVehicle.h"

using namespace godot;

void PlayerVehicle::_register_methods()
{
  register_method("_ready", &PlayerVehicle::_ready);
  register_method("_physics_process", &PlayerVehicle::_physics_process);

  register_property<PlayerVehicle, float>("max_speed", &PlayerVehicle::max_speed, (float)1.0);
  register_property<PlayerVehicle, float>("friction", &PlayerVehicle::friction, (float)0.1);
  register_property<PlayerVehicle, float>("acceleration", &PlayerVehicle::acceleration, (float)0.1);
  register_property<PlayerVehicle, float>("gravity", &PlayerVehicle::gravity, (float)30);
}

PlayerVehicle::PlayerVehicle()
{
}

PlayerVehicle::~PlayerVehicle()
{
  // Some cleanup here?
}

void PlayerVehicle::_init()
{
}

void PlayerVehicle::_ready()
{
  gameManager = cast_to<GameManager>(get_node("/root/Main/GameManager"));
  Godot::print(gameManager->get_name());
}

void PlayerVehicle::get_input()
{
  if (!gameManager->isGameOver)
  {
    Input *input = Input::get_singleton();
    input_dir = 0;
    if (input->is_action_pressed("Player_Right"))
    {
      input_dir += max_speed;
    }
    if (input->is_action_pressed("Player_Left"))
    {
      input_dir -= max_speed;
    }

    if (input_dir != 0)
    {
      velocity.x = Math::lerp(velocity.x, input_dir * max_speed, acceleration);
    }
    else
    {
      velocity.x = Math::lerp(velocity.x, 0, friction);
    }
  }
}

void PlayerVehicle::_physics_process(float delta)
{
  get_input();
  velocity = move_and_slide(velocity, Vector3::UP);

  velocity.y -= gravity * delta;
}
