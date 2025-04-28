import datetime

# Today's date
today = datetime.date(2025, 6, 25)

# Add 10 days
future_date = today + datetime.timedelta(days=42)

print(future_date)
