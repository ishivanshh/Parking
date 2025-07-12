
# Parking Lot Management System in C

This is a modular C project to simulate a parking lot with a waiting queue, type-based fee, logs, and password protection.

## ✅ Features
- Stack for LIFO parking slots
- Queue for waiting list
- Fee calculated based on car/bike
- Admin panel login with password masking
- Logs stored in `parking_log.txt`

## 🛠️ Compilation Instructions

### On Windows (using GCC/MinGW)
```bash
gcc src/main.c src/stack.c src/queue.c src/utils.c -o parking.exe
./parking.exe
```

### On Linux (remove conio.h and getch first)
```bash
gcc src/main.c src/stack.c src/queue.c src/utils.c -o parking
./parking
```

## 🔐 Default Credentials
- Username: `admin`
- Password: `1234`
