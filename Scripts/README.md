Scripts
---
These scripts were made specifically for removing the "busy-work" out of lab configurations in class. Do not use these if you dont know how to manually configure the labs yourself.

**WHEN USING THESE SCRIPTS RENAME YOUR NETWORK ADAPTOR TO: "mcse"**
> I will automate this later using [netsh](https://blogs.technet.microsoft.com/heyscriptingguy/2014/01/14/renaming-network-adapters-by-using-powershell) 


Troubleshooting
---
* If scripts does not change any of the network config:
    > Fix this by renaming your network adaptor from "Local Area Connection" to "mcse" (case-sensitive)
* .c files does not open or opens in a text editor
    > .c files need to be compiled first; use TDM-GCC MinGW Compiler if you're on a Windows Machine, or use GCC if you're running a Linux or MacOS Machine