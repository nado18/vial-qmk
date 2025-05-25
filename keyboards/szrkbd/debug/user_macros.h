#pragma once

enum user_macros {
  UM_ANGL = SAFE_RANGE,
  UM_SQUA,
  UM_CURL,
  UM_PARN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record);
