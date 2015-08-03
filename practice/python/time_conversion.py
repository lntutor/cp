time = raw_input()

if 'AM' in time:
    hh = (int) (time[:2])
    if hh == 12:
        hh = '00'
        print hh + time[2:8]
    else:
        print time[:8]
else:
    hh = (int) (time[:2])
    if hh != 12:
        hh += 12
        print `hh` + time[2:8]
    else:
        print time[:8]