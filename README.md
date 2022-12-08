# POINT WELDER 

<p>
	Current version: <b>V1</b><br>
	Planned next version: <b>V2</b> (IN PROGRESS)
</p>

<h1>Information ℹ️</h1>
<p>
	This is a home made point welder circuit that easily can be attached to a 12 V car battery to provide a good weld between two, thin, metal sheets, i.e. for battery cell connections.
</p>

<h1>Specifications ℹ️</h1>
<p>
	This section provides a summary of the different versions.
</p>

<h2>Point Welder V1</h2>
<p>
	Point Welder V1 proved that the circuit works (without fuses blowing and batteries exploding). It has a large 3D-printed housing containing everything excluding the cables for attaching to the car battery and for welding. It has a cascade of switches and relays to reliably control the huge current when operating. An Arduino Nano Every is the brain behind the circuit and is powered by the attached battery through a 12 V --> 5 V buck converter.<br><br>
	The cable from the connected battery's positive terminal goes through a 300 A fuse before anything else to ensure a redundant fail-safe. Also, the largest relay (rated at 200 A continuous draw) has a switch that needs to be on before it can work, as an additional safety feature.
</p>

<b>Pros:</b>
<ul>
	<li>✅ Fully operational with connection to only one (sufficently powerful) 12 V battery.</li>
	<li>✅ Easy to operate.</li>
	<li>✅ Safe and secure with redundant fail-safes.</li>
</ul>

<b>Cons:</b>
<ul>
	<li>❌ Large housing.</li>
	<li>❌ Not very nice looking.</li>
	<li>❌ Stiff cables, making it hard to operate.</li>
	<li>❌ Not modular with regards to external cables.</li>
	<li>❌ Impractical connectors for external battery.</li>
</ul>

<b>Improvements:</b>
<ul>
	<li>🟡 Time setting range from 10 to 100 ms instead of 50 to 200 ms.</li>
	<li>🟡 Custom made PCB for the electronics.</li>
	<li>🟡 Smaller, and nicer looking, housing.</li>
	<li>🟡 Second (smallest of the relays) relay powered by battery and not Arduino.</li>
	<li>🟡 Improved time setting code robustness in endpoints to end "flickering".</li>
	<li>🟡 Working LEDs.</li>
	<li>🟡 Detachable cables.</li>
	<li>🟡 Cables with softer isolation and multi-threaded.</li>
	<li>🟡 Crocodile connectors.</li>
</ul>
