#ifndef SERVER_CONSTANTS
#define SERVER_CONSTANTS

// ========== COMMON TEXT =============================

// INITIAL PROMPT
#define INITIAL_PROMPT "\
🚀✨ Welcome to JALGOAN People's Co-operative Bank ✨🚀\n\
\\How can I help you?\n\
Who are you?\n\
1️⃣. Admin 🧑‍💼\t2️⃣. Customer 👨‍👩‍👧‍👦\t3️⃣. Manager 📊\t4️⃣. Employee 🛠️\n\
Press any other number to exit. 🛑\n\
👉 Enter your Preferred choice: "

// LOGIN
#define LOGIN_ID "🔑 Enter your login ID: "
#define PASSWORD "🔒 Enter your password:\n# "
#define INVALID_LOGIN "❌ Oops! That login ID doesn’t seem to exist!$"
#define INVALID_PASSWORD "❌ The password entered doesn't match!$"
#define SALT_BAE "✨666✨"

// ACCOUNT SEARCH
#define GET_ACCOUNT_NUMBER "🔍 Please provide the account number you're looking for: "
#define GET_CUSTOMER_ID "🔍 Enter the customer ID of the customer you're searching for: "

#define ERRON_INPUT_FOR_NUMBER "⚠️ Oops! You entered alphabets where a number was expected or provided an invalid number!\nRedirecting you to the main menu...^"

#define INVALID_MENU_CHOICE "⚠️ That was an invalid choice! Redirecting to the main menu...^"

#define CUSTOMER_ID_DOESNT_EXIT "❌ No customer found for the given ID."
#define CUSTOMER_LOGIN_ID_DOESNT_EXIT "❌ No customer found for the provided login ID.$"

#define ACCOUNT_ID_DOESNT_EXIT "❌ No account found for the given account number."

#define TRANSACTIONS_NOT_FOUND "⚠️ No transactions found on this account!^"

// ========== ADMIN SPECIFIC TEXT =====================

// LOGIN WELCOME
#define ADMIN_LOGIN_WELCOME "🧑‍💼 Hello, Admin! Every privilege comes with a duty.\nEnter your login details:"
#define ADMIN_LOGIN_SUCCESS "🎉 Hey Customer, Welcome to Our Bank!"

// ADMIN MENU
#define ADMIN_MENU "\
1️⃣ Get Customer Details\n\
2️⃣ Get Account Details\n\
3️⃣ View Transaction History\n\
4️⃣ Add New Account\n\
5️⃣ Delete Account\n\
6️⃣ Modify Customer Information\n\
Press any other key to logout."

// ADD CUSTOMER
#define ADMIN_ADD_CUSTOMER_PRIMARY "📋 Enter the details for the **primary customer**:\n"
#define ADMIN_ADD_CUSTOMER_SECONDARY "📋 Enter the details for the **secondary customer**:\n"
#define ADMIN_ADD_CUSTOMER_NAME "👤 What's the customer's name?"
#define ADMIN_ADD_CUSTOMER_GENDER "👥 What’s the customer’s gender?\nEnter M for Male, F for Female, or O for Others: "
#define ADMIN_ADD_CUSTOMER_AGE "🔢 What's the customer’s age?"
#define ADMIN_ADD_CUSTOMER_AUTOGEN_LOGIN "🆔 The login ID for the customer is: "
#define ADMIN_ADD_CUSTOMER_AUTOGEN_PASSWORD "🔑 The password for the customer is: "
#define ADMIN_ADD_CUSTOMER_WRONG_GENDER "⚠️ Invalid gender choice! Redirecting you to the main menu...^"

// ADD ACCOUNT
#define ADMIN_ADD_ACCOUNT_TYPE "🏦 What type of account? Enter 1 for Regular or 2 for Joint: "
#define ADMIN_ADD_ACCOUNT_NUMBER "🏷️ The new account number is: "

// DELETE ACCOUNT
#define ADMIN_DEL_ACCOUNT_NO "❓ Enter the account number you wish to delete: "
#define ADMIN_DEL_ACCOUNT_SUCCESS "✅ Account successfully deleted! Redirecting to the main menu...^"
#define ADMIN_DEL_ACCOUNT_FAILURE "❌ Cannot delete this account—it still has money. Redirecting to the main menu...^"

// MODIFY CUSTOMER INFO
#define ADMIN_MOD_CUSTOMER_ID "🔎 Enter the ID of the customer to modify: "
#define ADMIN_MOD_CUSTOMER_MENU "What would you like to change?\n1️⃣ Name 2️⃣ Age 3️⃣ Gender\nPress any other key to cancel."
#define ADMIN_MOD_CUSTOMER_NEW_NAME "✏️ Enter the new name: "
#define ADMIN_MOD_CUSTOMER_NEW_GENDER "✏️ Enter the new gender: "
#define ADMIN_MOD_CUSTOMER_NEW_AGE "✏️ Enter the new age: "
#define ADMIN_MOD_CUSTOMER_SUCCESS "✅ Changes saved! Returning to the main menu.^"

#define ADMIN_LOGOUT "🛑 Logging out, Customer! Goodbye!$"

// ========== CUSTOMER SPECIFIC TEXT ==================

// LOGIN WELCOME
#define CUSTOMER_LOGIN_WELCOME "👨‍👩‍👧‍👦 Welcome, valued customer! Enter your credentials to access your account."
#define CUSTOMER_LOGIN_SUCCESS "🎉 Hello, dear customer!"

#define CUSTOMER_LOGOUT "👋 Logging you out now. Goodbye!$"

// CUSTOMER MENU
#define CUSTOMER_MENU "\
1️⃣ View Customer Details\n\
2️⃣ Deposit Money\n\
3️⃣ Withdraw Money\n\
4️⃣ Check Balance\n\
5️⃣ View Transactions\n\
6️⃣ Change Password\n\
7️⃣ Transfer Funds\n\
8️⃣ Apply for Loan\n\
9️⃣ Write Feedback\n\
Press any other key to logout.\n"

#define ACCOUNT_DEACTIVATED "❌ Your account has been deactivated!^"

// TRANSACTIONS
#define DEPOSIT_AMOUNT "💵 How much would you like to deposit?"
#define DEPOSIT_AMOUNT_INVALID "⚠️ Invalid amount entered!^"
#define DEPOSIT_AMOUNT_SUCCESS "✅ Amount deposited successfully!^"

#define WITHDRAW_AMOUNT "💸 How much would you like to withdraw?"
#define WITHDRAW_AMOUNT_INVALID "❌ Invalid withdrawal or insufficient balance!^"
#define WITHDRAW_AMOUNT_SUCCESS "✅ Withdrawal successful!^"

// PASSWORD MANAGEMENT
#define PASSWORD_CHANGE_OLD_PASS "🔑 Enter your old password: "
#define PASSWORD_CHANGE_OLD_PASS_INVALID "❌ Incorrect old password!"
#define PASSWORD_CHANGE_NEW_PASS "🔑 Enter the new password: "
#define PASSWORD_CHANGE_NEW_PASS_RE "🔑 Re-enter the new password: "
#define PASSWORD_CHANGE_NEW_PASS_INVALID "❌ Passwords do not match!^"
#define PASSWORD_CHANGE_SUCCESS "✅ Password changed successfully!^"

// ========== MANAGER SPECIFIC TEXT ====================

#define MANAGER_LOGIN_SUCCESS "🎉 Welcome, Manager!"
#define MANAGER_MENU "\
1️⃣ Activate Customer Accounts\n\
2️⃣ Deactivate Customer Accounts\n\
3️⃣ Assign Loan Applications to Employees\n\
4️⃣ Review Customer Feedback\n\
5️⃣ Change Password\n\
Press any other key to logout."

// ========== CUSTOMER FEEDBACK =======================
#define CUSTOMER_FEEDBACK "📝 Please leave your feedback:\n"

// ========== FILE PATHS ==============================
#define ACCOUNT_FILE "./records/account.bank"
#define CUSTOMER_FILE "./records/customer.bank"
#define EMPLOYEE_FILE "./records/employee.bank"
#define TRANSACTION_FILE "./records/transactions.bank"
#define LOAN_RECORD_FILE "./records/loan.bank"
#define CREDENTIALS_FILE "./admin-credentials.h"

#endif
