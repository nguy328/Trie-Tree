# Trie-Tree
Trie Tree Data Structure

# Lab 400: Replicate process configuration

Continuing from lab300, to replicate the process configuration


dblogin useridalias ADW
Configure mgr dynamic ports
```
edit param mgr
Add line
DYNAMICPORTLIST 10020-10030
stop/start mgr
```
Configure ./GLOBALS
```
edit param ./GLOBALS
Add line
ALLOWOUTPUTDIR /home/opc/oracle18/dirdat/
```
Configure Replicat process
```
edit param REP (INSERT SCREENSHOT)
add replicat REP, exttrail /home/opc/oracle18/dirdat/cc, begin now, checkpointtable ggadmin.ggschkpt
```

[Click here to go to lab 500](https://github.com/GaryHostt/GoldenGate2ADB/blob/master/Lab500.md)

# Lab 500: GoldenGate in-action

If you have reached this lab, then you have configured a full GoldenGate migration data sync. All that is left is to monitor your processes to see if they're working correctly. So let's continue.
```
ggsci oracle11
Start *
```
Ensures all extract processes have started
```
info all
```
Ensures each processes is correctly working
```
view report (EXT/PMP)
```
Ensures logging file is created
```
cd oracle11/dirdat/
```
Checks if file exists
Repeat for oracle18/dirdat/
```
ggsci oracle18
Start *
```
Ensures all extract processes have started
```
info all
```
Ensures each processes is correctly working
```
view report REP
```
Within SQLDeveloper:
Make changes in source database
Check if changes synced to target database
```
ggsci oracle18
Command: stats replicat REP
```

Congratulations, you have completed your day in the life of Tim successfully. 
