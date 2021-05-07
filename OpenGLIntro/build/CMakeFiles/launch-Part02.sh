#!/bin/sh
bindir=$(pwd)
cd /home/cshome/p/pjitsawatpaiboon/Desktop/342/OpenGLIntro/Part02/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		GDB_COMMAND-NOTFOUND -batch -command=$bindir/gdbscript  /home/cshome/p/pjitsawatpaiboon/Desktop/342/OpenGLIntro/build/Part02 
	else
		"/home/cshome/p/pjitsawatpaiboon/Desktop/342/OpenGLIntro/build/Part02"  
	fi
else
	"/home/cshome/p/pjitsawatpaiboon/Desktop/342/OpenGLIntro/build/Part02"  
fi
