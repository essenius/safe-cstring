// Copyright 2023 Rik Essenius
// 
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
// except in compliance with the License. You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and limitations under the License.

#include <SafeCString.h>

char target[10] = { 0 };

void setup() {
	Serial.begin(115200);
	delay(50);
	Serial.println(SafeCString::sprintf(target, "%d", 12345));                   // 5 (number of characters written)
	Serial.println(target);                                                      // 12345
	Serial.println(SafeCString::strcat(target, "abcde"));                        // 12345abcd (max 10 characters, including \0)
	Serial.println(target);                                                      // 12345abcd
	Serial.println(SafeCString::strcpy(target, "zyxwv"));                        // zyxwv
	Serial.println(target);                                                      // zyxwv

	char* pointer = target + 5;
	Serial.println(SafeCString::pointerStrcpy(pointer, target, "98765"));        // 9876
	Serial.println(target);                                                      // zyxwv9876

	pointer = target + 3;
	Serial.println(SafeCString::pointerSprintf(pointer, target, "yz%d", 12345)); // 7 (number of characters written)
	Serial.println(target);                                                      // zyxyz1234
}

void loop() {}