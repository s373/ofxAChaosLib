/*
	32/64 bits A-Chaos Lib in openFrameworks	
	(c) s373.net/x 2004, 2012, 2015
	http://s373.net/code/A-Chaos-Lib/A-Chaos.html
	programmed by Andre Sier, revised 2015
	License: MIT
*/

This A-Chaos Lib extends a tiny bit Richard Dudas' original "ChaosCollectionFAT" from October 1996 on the Max Programming Environment.

A-Chaos Lib 1.01
(a chaotic library for max systems / march 2004 (ppc+9) / jan 2005 (win)/ jun 2006 (ub))


A-Chaos Lib is a library of non-linear strange attractors for the max programming environment extended from Richard Dudas' Chaos Collection, including the source.


(24 dynamic non-linear systems :: a-baker, a-clifford, a-collatz, a-duffing, a-fibonacci, a-ginger, a-henon-heilles, a-henon, a-henonf, a-henonphase, a-ikeda, a-jong, a-logistic, a-logistic1, a-lorenz, a-lorenz.e,a-lyapunov, a-navier-stokes, a-navier-stokes.e, a-rossler, a-stein, a-stein1, a-torus and a-verhulst)

A-Chaos Lib web page
http://s373.net/code/A-Chaos-Lib/A-Chaos.html


Below you can find the original README from Richard Dudas. I asked Richard Dudas for permission to extend his collection, circa 2003+, after being immersed doing c.( ) (a 2h movie and an audio cd, still unreleased). 

http://andre-sier.com/projects/c-lv-copy/
http://andre-sier.com/projects/c/

-André Sier (astronaut@s373.net)



	Chaos Collection (first release October 1996)

	The Chaos Collection is a suite of Max (Macintosh) External Objects which generate numeric values according to theories of certain non-linear dynamic systems: iterations of recursive equations and solutions of differential equations.  These objects are "Fat" - they contain code for both 68k and PowerPC versions of Max.

	Those who are familiar with IRCAM's software "PatchWork" will recognize that these objects correspond to those included in the Orbitals section of PatchWork's Chaos Library written by Mikhail Malt.  It was Mikhail's enthusiasm and support for my desire to convert this library to the real-time environment of Max that helped get the initial project off the ground.

	Many of the objects include abstraction versions (denoted bu the suffix ".a").  These versions are not intended to be used in practical situations, but rather to be studied; they are provided as an aid to understanding the computational processes on which the external objects are based.  In general, the abstraction versions function similarly to the actual external objects which they represent, but may contain slight differences such as the messages they accept, the order of the inlets, etc...

	The objects and abstractions share a similar naming convention: 
	  their names all begin with "chaos-" 

	The External Objects themselves share a common interface:
	  a "bang" in the left inlet calculates an iteration of the equation
	  the equation's initial values may be set by sending an int or float to any one of the inlets
	  (a number in the leftmost inlet will also trigger the calculation)
	  the "set" message in the left inlet may also be used to set the initial values
	  (the "set" message will not trigger the calculation)
	  the "reset" message in the left inlet will reset the object's last initial values
	  the "info" message will display all current and initial valuers in the Max window

	The .help files provided also share a common user-interface.
	  a "metro" object is used to trigger a stream of calculations
	  The calculations are displayed graphically - so there's no sound !!
	  (the object's output is sent to a multislider or lcd depending on the object)
	  The lcd object may be cleared using the "clear" message provided.
	  (in some cases the scale of the display may be changed)

	Many of the equations used are very sensitive and require numbers within a specific range.  No attempt has been made to prevent you from throwing these chaotic systems out of balance.  
	So, if one set of values doesn't work, try another!
	A larger, more informative manual will hopefully be provided with the next release of the Chaos Collection. (You may want to refer to the PatchWork Chaos Library's documentation.)

	Caveats:
	You may want to disable overdrive or change the speed of the metro when using Max 3.0 or earlier!!!  The lcd object provided with these versions of Max tends to crash on fast machines.  This problem has been fixed in the lcd which comes with Max 3.5.

	Although these objects are provided "as-is", bug reports are most certainly welcome.

	-Richard Dudas (dudas@ircam.fr)


