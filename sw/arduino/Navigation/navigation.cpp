/**
 * @brief Simple balloon positioning Library
 */

/*Author: Matias Vidal*/

#include "navigation.h"

/*Public methods*/

/**
 * Initiate servos and variables of the movement library.
 */
void Move::init(void) {
	left_servo.attach(LFT_SRV_PIN);
        right_servo.attach(RGT_SRV_PIN);
	this.dest_lat = -33.457712;
	this.dest_lng = -70.662816;
	this.dest_alt = 400
	this.direction = 'F'
	this.spd = 0;
}

/**
 * Update position and orientation of the radiosonde.
 * @param yaw Yaw Euler angle of the radiosonde.
 * @param pitch Pitch Euler angle of the radiosonde.
 * @param roll Roll Euler angle of the radiosonde.
 * @param lat Latitude coordinate of the radiosonde.
 * @param lng Longitude coordinate of the radiosonde.
 * @param alt Current altitude of the radiosonde.
 */
void Move::update(float yaw, float pitch, float roll, float lat, float lng, float alt) {
	this.yaw = yaw;
	this.pitch = pitch;
	this.roll = roll;
	this.lat = lat;
	this.lng = lng;
	this.alt = alt;
}

/**
 * Set the destination coordinates of the radiosonde.
 * @param lat Destination's latitude.
 * @param lng Destination's longitude.
 * @param alt Destination's altitude.
 */
void Move::setDestCoord(float lat, float lng, float alt) {
	this.dest_lat = lat;
	this.dest_lng = lng;
	this.dest_alt = alt;
}

/**
 * Moves the radiosonde to a given coordinate and altitude, at a certain speed.
 * @param lat Destination latitude.
 * @param lng Destination's longitude.
 * @param alt Destination's altitude.
 * @param spd spd The new radiosonde's speed.
 */
void Move::toCoordinates(float lat, float lng, float alt, uint8_t spd) {
	this.setDestCoord(lat, lng, alt);
	this.servos2dest();
	this.setSpeed(spd);
}

/**
 * This method moves the servos at the desired orientation, in order to move
 * to the destination.
 */
void Move::servos2dest() {

	left_servo.write(left_angle);
	right_servo.write(right_angle);
}

/**
 * Activate the motors at a certain speed to move the radiosonde forward.
 */
void Move::forward() {
	analogWrite(LFT_MTR_PIN1, this.spd);
        digitalWrite(LFT_MTR_PIN2, LOW);
        analogWrite(RGT_MTR_PIN1, this.spd);
        digitalWrite(RGT_MTR_PIN2, LOW);
}

/**
 * Activate the motors at a certain speed to move the radiosonde to the left.
 */
void Move::toTheLeft() {
	analogWrite(LFT_MTR_PIN1, this.spd);
        digitalWrite(LFT_MTR_PIN2, LOW);
        digitalWrite(RGT_MTR_PIN1, LOW);
        analogWrite(RGT_MTR_PIN2, this.spd);
}

/**
 * Active the motors at a certain speed to move the radiosonde to the right.
 */
void Move::toTheRight() {
	digitalWrite(LFT_MTR_PIN1, LOW);
        analogWrite(LFT_MTR_PIN2, this.spd);
        analogWrite(RGT_MTR_PIN1, this.spd);
        digitalWrite(RGT_MTR_PIN2, LOW);
}

/**
 * Activate the motor at a certain speed to move backwards.
 */
void Move::backwads() {
	digitalWrite(LFT_MTR_PIN1, LOW);
        analogWrite(LFT_MTR_PIN2, this.spd);
        digitalWrite(RGT_MTR_PIN1, LOW);
        analogWrite(RGT_MTR_PIN2, this.spd);
}

void Move::setSpeed(uint8_t spd) {
	this.spd = spd;
	if (self.direction == 'B') {
		this.backwards();
	}
	else if (self.direction == 'R'){
		this.toTheRight();
	}
	else if (self.direction == 'L') {
		this.toTheLeft();
	}
	else {
		this.forward();
	}
}
