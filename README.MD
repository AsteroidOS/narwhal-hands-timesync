# hands-timesync
hands-timesync is a minimal binary that sets the hands time on LG Watch W7 running the android kernel. It is dependent on QT. Essentially, it just formats the time string and then writes it to sysfs, where the sop716 driver that talks to the hands actually does all the heavy lifting. There is currently no option to set time manually. 
