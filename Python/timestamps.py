import datetime

# First, define UTC+8 timezone
utc_plus_8 = datetime.timezone(datetime.timedelta(hours=8))

# Now create your datetime in UTC+8
dt = datetime.datetime(2025, 4, 26, 19, 0, tzinfo=utc_plus_8)

# Then, convert it to UTC
dt_utc = dt.astimezone(datetime.timezone.utc)

# Finally, get the Unix timestamp
timestamp = int(dt_utc.timestamp())

print(timestamp)
