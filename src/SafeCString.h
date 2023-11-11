// Copyright 2022-2023 Rik Essenius
// 
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
// except in compliance with the License. You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and limitations under the License.

// The standard sprintf, strcat and strcpy are not safe, and the *p options aren't much better.
// The ones defined here are safer as they take buffer sizes into account.

#ifndef HEADER_SAFECSTRING
#define HEADER_SAFECSTRING

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <cstring>
#include <cstdio>

class SafeCString {
public:
    template <size_t BufferSize, typename... Arguments>
    static int pointerSprintf(char* const pointer, char(&buffer)[BufferSize], const char* format, Arguments ... arguments) {
        auto charactersUsed = pointer - buffer;
        if (charactersUsed < 0 || charactersUsed > BufferSize) return 0;
        return snprintf(pointer, BufferSize - charactersUsed, format, arguments...);
    }

    template <size_t BufferSize>
    static char* pointerStrcpy(char* const pointer, char(&buffer)[BufferSize], const char* source) {
        auto charactersUsed = pointer - buffer;
        // if the source is null or pointer is not in the right range, do nothing
        if (source == nullptr || charactersUsed < 0 || charactersUsed >= static_cast<long long>(BufferSize)) return pointer;
        strncpy(pointer, source, BufferSize - charactersUsed - 1);
        buffer[BufferSize - 1] = 0;
        return pointer;
    }

    template <size_t BufferSize, typename... Arguments>
    static int sprintf(char(&buffer)[BufferSize], const char* const format, Arguments ... arguments) {
        const int size = BufferSize;

        return snprintf(buffer, size, format, arguments...);  // NOLINT(clang-diagnostic-format-nonliteral)
    }

    template <size_t BufferSize>
    static char* strcat(char(&buffer)[BufferSize], const char* source) {
        if (source != nullptr) {
            strncat(buffer, source, BufferSize - strlen(buffer) - 1);
            buffer[BufferSize - 1] = 0;
        }
        return buffer;
    }

    template <size_t BufferSize>
    static char* strcpy(char(&buffer)[BufferSize], const char* source) {
        if (source != nullptr) {
            strncpy(buffer, source, BufferSize);
            buffer[BufferSize - 1] = 0;
        }
        return buffer;
    }
};
#endif
