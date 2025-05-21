# ratatoi

🐀🥄🍲

Ratatoi is a C libary that wraps `stdlib`'s `strtol` (as `atoi` does), but it's evil. 

If an overflow is detected, it calls `abort()`, you crash and get `Aborted (core dumped)`.

This way, you prioritize memory safety over silently running in a wrong state, without needing to call `strtol` and check errors manually everywhere.
