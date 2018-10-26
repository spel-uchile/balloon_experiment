/**
 * @brief Simple balloon positioning Library
 */

/*Author: Matias Vidal*/

/*Requiered Libraries*/
#include <Arduino.h>
#include  <Servo.h>
#include "pines.h"

/**
 * @class Move
 * @brief Class for movement management
 */
class Move {
	Servo left_servo;
	Servo right_servo;
	float yaw;
	float pitch;
	float roll;
	float lat;
	float lng;
	float alt;
	float dest_lat;
	float dest_lng;
	float dest_alt;
	char direction;
	uint8_t spd;

	public:
		/*Public Members*/

		/*Base constructor (null)*/
		Move() {}
		// Methods
		void init(void);
		void update(float yaw, float pitch, float roll, float lat, float lng, float alt);
		void setDestCoord(float lat, float lng, float alt);
		void toCoordinates(float lat, float lng, float alt, uint8_t spd);
		void servos2dest();
		void forward();
		void toTheLeft();
		void toTheRight();
		void backwards();
		void setSpeed(uint8_t spd);
};
