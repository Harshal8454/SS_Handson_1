#ifndef GLOBALS_H
#define GLOBALS_H
#include <time.h>

#define CUSTOMERS_FILE "../data/CUSTOMERS_DB"
#define EMPLOYEES_FILE "../data/EMPLOYEES_DB"
#define ADMIN_FILE "../data/ADMIN_DB"
#define RECORDS_FILE "../data/RECORDS_DB"
#define LOANS_FILE "../data/LOANS_DB"
#define TRANSACTIONS_FILE "../data/TRANSACTIONS_DB"
#define USERNAME_SIZE 30
#define PASSWORD_SIZE 15
#define FEEDBACK_SIZE 300
#define RES_BODY_SIZE 10240
#define MAX_ARGUMENT_SIZE 1024
#define SERVER_PORT 8080

typedef enum
{
    False,
    True
} Bool;

typedef enum
{
    NONE,
    CUSTOMER,
    EMPLOYEE,
    ADMIN
} UserType;

typedef enum
{
    REGULAR = 1,
    MANAGER
} Role;

typedef struct
{
    int user_id;
    UserType user_type;
    Role role;
    char username[USERNAME_SIZE];
} Token;

typedef struct
{
    int argc;
    Token user;
    char arguments[MAX_ARGUMENT_SIZE];
} Request;

typedef struct
{
    Token user;
    char body[RES_BODY_SIZE];
} Response;

typedef struct
{
    int customer_id;
    double balance;
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    Bool is_active;
    Bool in_session;
    char feedback[FEEDBACK_SIZE];
} Customer;

typedef struct
{
    Role role;
    int employee_id;
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    Bool in_session;
} Employee;

typedef struct
{
    int admin_id;
    char username[USERNAME_SIZE];
    char password[PASSWORD_SIZE];
    Bool in_session;
} Admin;

typedef enum
{
    PENDING = 1,
    IN_REVIEW,
    GRANTED,
    REJECTED
} LoanStatus;

typedef enum
{
    CAR_LOAN = 1,
    HOME_LOAN,
    GOLD_LOAN
} LoanType;

typedef struct
{
    int loan_id;
    double amount;
    LoanType type;
    int customer_id;
    int employee_id;
    LoanStatus status;
} Loan;

typedef struct
{
    int customers_count;
    int employees_count;
    int admins_count;
    int loans_count;
    long long transactions_count;
} Record;

typedef struct {
    int transaction_id;
    int sender_id;
    int receiver_id;
    double amount;
    time_t time;
} Transaction;


char *loan_type_names[] = {
    "", "CAR LOAN", "HOME LOAN", "GOLD LOAN"};

char *loan_status_names[] = {"", "PENDING", "IN REVIEW", "GRANTED", "REJECTED"};

char *transaction_type_names[] = {"NONE", "WITHDRAW", "DEPOSIT"};

#endif