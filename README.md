## About

LiteStay is a lightweight hotel management software for small-scale properties

This project is a submission to my CS3307 final.

## Running the code

1. Clone the repo
2. Install [SQLite](https://www.sqlite.org/)
3. Open the project in QT Creator
4. Click build and run
5. Log in with credientials:

## Using this progrm

1. Run the program
2. Enter _admin_ into username and an empty password to log in as a adminstrator.
   Or type _defaultuser_ and an empty password to log in as a user with restricted priveilege.
   These accounts will be recreated if you were to delete them in the program
3. To add a booking, go to add booking tab. Select the booking start date and end date,
   click find avaliable room which shows which room is unbooked during those dates. Click on
   the desired room, enter guest names and click add booking.
4. To add/delete a room or employee record, Make sure you are logged in as an admin
   (see step 2 if u need help), navigate to their respective tabs, fill in information then click add, or simply click the delete button to delete a record.

## Next steps for this project

There are quite a number of features that are not yet implemeted from requirements
These are ranked from most important/urgent to least

- Error message when user does something wrong
- Searching function with conditions
- Custom SQL commands for setting up database
- Better database schema, security controls and transaction safety
