# throttle-for
Throttles CPU cores for a given time span

# Usage
`throttlefor.exe [MAX_CPU_STATE] [SECONDS]`
* `MAX_CPU_STATE` is the maximum power state of the CPU (1-100). Defaults to 40.
* `SECONDS` sets for how long to keep the CPU throttled before setting the power state back to 100. Default is 10.

# Automatic Overheat Protection
Some older laptops do no properly throttle using the on-chip DTS (Digital Temperature
Sensor). This can lead to unexpected system shutdown.

You can use [Core Temp](http://www.alcpu.com/CoreTemp/) for automatic throttling to prevent overheating.
Open Core Temp, Options -> Overheat Protection. Select `throttlefor.exe` for *Execute program*.
