# Trie-Tree
Trie Tree Data Structure

# Lab 400: Replicate process configuration

Continuing from lab300, to replicate the process configuration

```
dblogin useridalias ADW
Configure mgr dynamic ports
edit param mgr
Add line
DYNAMICPORTLIST 10020-10030
stop/start mgr
Configure ./GLOBALS
edit param ./GLOBALS
Add line
ALLOWOUTPUTDIR /home/opc/oracle18/dirdat/
Configure Replicat process
edit param REP (INSERT SCREENSHOT)
add replicat REP, exttrail /home/opc/oracle18/dirdat/cc, begin now, checkpointtable ggadmin.ggschkpt
```

[Click here to go to lab 500](https://github.com/GaryHostt/GoldenGate2ADB/blob/master/Lab500.md)
