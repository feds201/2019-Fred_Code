/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/*
-one button 
[cargo mode 
hatch mode]
-cargo mode has 3 hights
-lowest hatch hight is the home position
-one button will switch from how high it is
-limit swatchs are on the top and buttom of robot
   -limit switchs control the direction the lift is going from up to down or down to up

Lift: Switch position to low, middle, and high
Switch: Switch from cargo to hatch & go back to home
Home: Send lift to home position
Move: Carry out direction from lift
*/


#pragma once

#include"RobotMap.h"


class Elevator {
 public:
  Elevator();
  void Lift();
  void Lower(bool hasHatch);
  void Refresh(bool isHatch, bool isCargo);
  void Override(double speed, bool isOverride);
  int getEncPos();
  int getEncVel();
  double getCurrent();
  std::string getTarget();
  int getErr();

  private:
   
   bool configMode = CONFIG_MODE;
   
   int pos = 0; // 0 = Home, 1 = Hatch Low, 2 = Cargo Low, 3 = Hatch Mid, 4 = Cargo Mid, 5 = Hatch High, 6 = Cargo High

   int posList[7] = {0, 0, 0, 0, 0, 0, 0}; //Hatch Mid, Hatch High, Cargo Low, Cargo Mid, Cargo High

   int currentPos = 0;
   int overridePos = 0;
   bool isOverridden = false;
   bool wasOverridden = false;

   double P = elevator_P;
   double I = elevator_I;
   double D = elevator_D;

   bool manualMode = elevatorManualMode;

   WPI_TalonSRX motor{elevatorMotor};

   frc::DigitalInput topLimit{topLimitSwitch};
   frc::DigitalInput bottomLimit{bottomLimitSwitch};

};