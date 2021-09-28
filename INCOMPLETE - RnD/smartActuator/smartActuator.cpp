void $_convertFaults$ () {
    int faults;
	int8 final;
	int bit = 1;
	smRead(VariableIDs._faults_main, faults);
	
	// Isolated the each bit within byte 4 of "Actuator feedback" PGN 65326
	for(int i = 1; i < 9; i++){	
		// final = bit & faults;
		final = faults & 0b00000001;
		switch(i){
			case 1:		
				smWrite(VariableIDs._fault_volltage, final);
				break;
			case 2:		
				smWrite(VariableIDs._fault_current, final);
				break;
			case 3:		
				smWrite(VariableIDs._fault_position, final);
				break;
			case 4:		
				smWrite(VariableIDs._fault_motorCircuit, final);
				break;
			case 5:		
				smWrite(VariableIDs._fault_temperature, final);
				break;
			case 6:		
				smWrite(VariableIDs._fault_seachHome, final);
				break;
			case 7:		
				smWrite(VariableIDs._fault_communication, final);
				break;
			case 8:
				smWrite(VariableIDs._fault_circuit, final);
				break;
		}
		faults = faults >> 1;
		// bit *= 2; // 0000 0001 -> 0000 0010 -> 0000 0100 -> ....
		
	}
}

void $_positionSlider$ () {
	int maxX = 500; 	// max sliding x value
	int minX = 10;  	// min sliding x value
	int slideX = 125; 	// sliding x adjustment 	50+75+15+10 = 150 originally;
	int slideY = 45;  	// sliding y adjustment 	45+36+510 = 591 origingally;
	int touchX;
	int temp;
	float target;
	
	smRead(VariableIDs.Touch_Current_X, touchX);

	// Bounds for the sliding bar	
	target = ((touchX - 140)/5);
	if(target < 0){
		target = 0;
	} else if(target > 100){
		target = 100;
	}

	// screen update
	ScreenPositionData scr;
	scr.ObjectID = ScreenObjectIDs.EWPositionCircle;
    scr.Recurrance = 20;
    scr.AnimationType = AnimationTypes.FastInAccelerator;
    scr.AnimationFactor = 100;
    temp = touchX - slideX;
    temp < minX ? scr.XValue = minX : temp > maxX ? scr.XValue = maxX : scr.XValue = temp;
	scr.YValue = slideY;
	SendActionObject(ApplicationIDs.Screen, ActionIDs.Screen_AnimatePosition, @scr);
    SendAction(ApplicationIDs.Screen, ActionIDs.Screen_AnimatePosition, ActionData.Empty );

	
	smWrite(VariableIDs._actuator_target, target);
	// smWrite(VariableIDs._debug1, touchX + slideX);
	smWrite(VariableIDs._debug2, touchX);
	smWrite(VariableIDs._debug3, slideY);
}

//---------------------------------------------------------------------------------------------
// Murphy Scripting
// - Leave EventName as $_speedSlider$ for main script method
//---------------------------------------------------------------------------------------------
void $_speedSlider$ () {
    int maxX = 500; 	// max sliding x value
	int minX = 10;  	// min sliding x value
	int slideX = 125; 	// sliding x adjustment 	50+75+15+10 = 150 originally;
	int slideY = 45;  	// sliding y adjustment 	45+36+510 = 591 origingally;
	int touchX;
	int temp;
	float speed;
	
	smRead(VariableIDs.Touch_Current_X, touchX);

	// Bounds for the sliding bar	
	speed = ((touchX - 140)/10);
	if(speed < 0){
		speed = 0;
	} else if(speed > 50){
		speed = 50;
	}

	// screen update
	ScreenPositionData scr;
	scr.ObjectID = ScreenObjectIDs.EWSpeedCircle;
    scr.Recurrance = 20;
    scr.AnimationType = AnimationTypes.FastInAccelerator;
    scr.AnimationFactor = 100;
    temp = touchX - slideX;
    temp < minX ? scr.XValue = minX : temp > maxX ? scr.XValue = maxX : scr.XValue = temp;
	scr.YValue = slideY;
	SendActionObject(ApplicationIDs.Screen, ActionIDs.Screen_AnimatePosition, @scr);
    SendAction(ApplicationIDs.Screen, ActionIDs.Screen_AnimatePosition, ActionData.Empty );

	
	smWrite(VariableIDs._actuator_speed, speed);
	// smWrite(VariableIDs._debug1, touchX + slideX);
	smWrite(VariableIDs._debug2, touchX);
	smWrite(VariableIDs._debug3, slideY);
}

//---------------------------------------------------------------------------------------------
// Murphy Scripting
// - Leave EventName as $_sendActuatorMessage$ for main script method
//---------------------------------------------------------------------------------------------
void $_sendActuatorMessage$ () {
	int64 position;
    int64 speed;
	int64 stop;
	int64 home;
	int show;
				// 		1			2			3			4				5			6			7				8
				//  1111 1111    1111 1111    1111 1111    1111 1111    1111 1111    1111 1111    1111 1111    1111 1111
	//int64 message = 0b1111111111111111111111111111111111111111111111111111111111111111;
	int64 message = 0b0000000000000000000000000000000000000000000000000000000000000000;		
	
	smRead(VariableIDs._send_show, show);
	smRead(VariableIDs._actuator_target, position);
	smRead(VariableIDs._actuator_speed, speed);
	smRead(VariableIDs._actuator_mode, home);
	smRead(VariableIDs._actuator_stop, stop);
	
	show == 1 ? smWrite(VariableIDs._send_show, 0) : smWrite(VariableIDs._send_show, 1); 
	
	message = (message | home) << 1;
	message = (message | stop) << 12;
	message = (message | position);
	
	smWrite(VariableIDs._actuator_send1, message);
	
	message = message << 12;
	message = (message | speed) << 19;
	message = message & 0x00000000ffffffff;
	
	smWrite(VariableIDs._actuator_send2, message);
	/*
	message = message ^ (position << 21);	//21
	message = message ^ (speed << 33);		//33		
	message = message ^ (home << 45);		//45
	message = message ^ (stop << 46);		//46
	*/
	//message = message & (position << 56);
	
	sendEvent(EventIDs.Send_Tx_Actuator_Command);
}
