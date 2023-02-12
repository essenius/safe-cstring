
#include <SafeCString.h>

char target[10] = { 0 };

void setup() {
	Serial.begin(115200);
	delay(50);
	Serial.println(SafeCString::sprintf(target, "%d", 12345)); // should show 5 (number of characters written)
	Serial.println(target); // should show 12345
	Serial.println(SafeCString::strcat(target, "abcde")); // should show 12345abcd, as target is 10 characters (including \0)
	Serial.println(target); // should show 12345abcd
	Serial.println(SafeCString::strcpy(target, "zyxwv")); // should show zyxwv
	Serial.println(target); // should show zyxwv

	char* pointer = target + 5;
	Serial.println(SafeCString::pointerStrcpy(pointer, target, "98765")); // should show 9876
	Serial.println(target); // should show zyxwv9876

	pointer = target + 3;
	Serial.println(SafeCString::pointerSprintf(pointer, target, "yz%d", 21345)); // should show 6 (number of characters written)
	Serial.println(target); // should show zyxyz1234
}

void loop() {}