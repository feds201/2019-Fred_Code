#include "Climber.h"

Climber::Climber() {

    front1.Set(frc::DoubleSolenoid::Value::kReverse);
    front2.Set(frc::DoubleSolenoid::Value::kReverse);
    back1.Set(frc::DoubleSolenoid::Value::kReverse);
    back2.Set(frc::DoubleSolenoid::Value::kReverse);
    tractiondeploy.Set(frc::DoubleSolenoid::Value::kReverse);
    //This makes sure that all of the pistons are retracted by default

    tractionwheel.Set(0);
    //This makes sure that the motor for the wheel is off by default

}

void Climber::incStage(){

    if((stage+1) <= 5){
    stage++;
    }
    excStage();
    //This makes the stage increase by 1 if the resulting stage doesn't go above 5

}
  void Climber::decStage(){

      if((stage-1) >= 0){
      stage--;
    }
      excStage();
    //This makes the stage decrease by 1 if the resulting stage doesn't go below 0

  }
  void Climber::setWheel(double speed){

      if(stage == 2){
      tractionwheel.Set(speed);
      }else{
        tractionwheel.Set(0);
        //This sets the speed of the traction wheel; if it's in any stage but 2, it sets the speed to 0
      }
  }

  void Climber::excStage(){

      switch(stage){

          case 1:

            liftFront();
            liftBack();

            break;
            //This case extends all of the pistons on the robot except for the one for the traction wheel
        case 2:

            deployArm();

            break;
            //This case extends the traction wheel (but does not run the motor for the traction wheel)
        case 3:
        
            liftFront();
            deployArm();

            break;
            //This case retracts the pistons on the front of the robot and retracts the traction wheel
        case 4:

            liftBack();
            break;
            //This case retracts the pistons on the back of the robot

        default :

            liftFront(false);
            liftBack(false);
            deployArm(false);
            //This is the default case for the robot. All of the pistons on the robot are retracted.

      }

  }
  void Climber::liftFront(){

      if(front1.Get() == frc::DoubleSolenoid::Value::kReverse){
          front1.Set(frc::DoubleSolenoid::Value::kForward);
          front2.Set(frc::DoubleSolenoid::Value::kForward);
      }else{
          front1.Set(frc::DoubleSolenoid::Value::kReverse);
          front2.Set(frc::DoubleSolenoid::Value::kReverse);
      }
    //If this is set to true, the front 2 pistons deploy; if it is false, the front 2 pistons retract

  }
  void Climber::liftBack(){

      if(back1.Get() == frc::DoubleSolenoid::Value::kReverse){
          back1.Set(frc::DoubleSolenoid::Value::kForward);
          back2.Set(frc::DoubleSolenoid::Value::kForward);
      }else{
          back1.Set(frc::DoubleSolenoid::Value::kReverse);
          back2.Set(frc::DoubleSolenoid::Value::kReverse);
      }
    //If this is set to true, the back 2 pistons deploy; if it is false, the back 2 pistons retract

  }
  void Climber::deployArm(){

      if(tractiondeploy.Get() == frc::DoubleSolenoid::Value::kReverse){
          tractiondeploy.Set(frc::DoubleSolenoid::Value::kForward);
      }else{
          tractiondeploy.Set(frc::DoubleSolenoid::Value::kReverse);
      }
        //If this is set to true, the traction wheel is deployed; if it is false, the traction wheel retracts

  }


void Climber::liftFront(bool state){

      if(state){
          front1.Set(frc::DoubleSolenoid::Value::kForward);
          front2.Set(frc::DoubleSolenoid::Value::kForward);
      }else{
          front1.Set(frc::DoubleSolenoid::Value::kReverse);
          front2.Set(frc::DoubleSolenoid::Value::kReverse);
      }
    //If this is set to true, the front 2 pistons deploy; if it is false, the front 2 pistons retract

  }
  void Climber::liftBack(bool state){

      if(state){
          back1.Set(frc::DoubleSolenoid::Value::kForward);
          back2.Set(frc::DoubleSolenoid::Value::kForward);
      }else{
          back1.Set(frc::DoubleSolenoid::Value::kReverse);
          back2.Set(frc::DoubleSolenoid::Value::kReverse);
      }
    //If this is set to true, the back 2 pistons deploy; if it is false, the back 2 pistons retract

  }
  void Climber::deployArm(bool state){

      if(state){
          tractiondeploy.Set(frc::DoubleSolenoid::Value::kForward);
      }else{
          tractiondeploy.Set(frc::DoubleSolenoid::Value::kReverse);
      }
        //If this is set to true, the traction wheel is deployed; if it is false, the traction wheel retracts

  }