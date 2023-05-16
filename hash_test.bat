@echo off

echo off
set message=hehehe

echo Testing MD5
(echo %message% && echo 1) |.\hash_program.exe

echo Testing SHA224
(echo %message% && echo 2) |.\hash_program.exe

echo Testing SHA256
(echo %message% && echo 3) |.\hash_program.exe

echo Testing SHA384
(echo %message% && echo 4) |.\hash_program.exe

echo Testing SHA512
(echo %message% && echo 5) |.\hash_program.exe

echo Testing SHA3-224
(echo %message% && echo 6) |.\hash_program.exe

echo Testing SHA3-256
(echo %message% && echo 7) |.\hash_program.exe

echo Testing SHA3-384
(echo %message% && echo 8) |.\hash_program.exe

echo Testing SHA3-512
(echo %message% && echo 9) |.\hash_program.exe

echo Testing SHAKE128
(echo %message% && echo 10) |.\hash_program.exe

echo Testing SHAKE256
(echo %message% && echo 11) |.\hash_program.exe

echo Done!

pause