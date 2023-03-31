#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

//structs
struct date
{
    int day;
    int month;
    int year;
};

struct user
{
    char type[10];
    char name[20];
    char family[20];
    char password[30];
    char gender[8];
    int id;
    int national_id_code;
    struct date date;
    int aprrove_number;
    int active;
    int money;
};

typedef struct __NODE__
{
    struct user usr;
    struct __NODE__ *next;
}Node;

struct time_limit
{
    int start;
    int end;
};

struct self
{
    int id;
    char name[30];
    char location[30];
    int capacity;
    char type[20];
    char meal[10];
    struct time_limit lunch;
    struct time_limit dinner;
};

struct food
{
    int id;
    char name[30];
    char type[20];
    int price;
};

struct meal_plan
{
    int self_id;
    struct date tarikh;
    char type[20];
    int food_id;
    int count; 
};  

struct reserve
{
    int student_id;
    int self_id;
    int food_id;
    struct date tarikh_reserve;
    char meal[8];
};

struct poll 
{
    char question[128];
    char op1_t[128];
    char op2_t[128];
    char op3_t[128];
    char op4_t[128];
    int op1;
    int op2;
    int op3;
    int op4;
    struct date end_date;
};

typedef struct __NODE_POLL__
{
    struct poll poll;
    struct __NODE_POLL__ *next;
}Node_poll;

struct news
{
    char title[64];
    char context [256];
    struct date end_date;
};

typedef struct __NODE_FOOD__
{
    struct food FOOD;
    struct __NODE_FOOD__ *next;
}Node_food;

typedef struct __NODE_SELF__
{
    struct self SELF;
    struct __NODE_SELF__ *next;
}Node_self;

typedef struct __NODE_MEALPLAN__
{
    struct meal_plan MEALPLAN;
    struct __NODE_MEALPLAN__ *next;
}Node_meal_plan;

typedef struct __NODE_RESERVE__
{
    struct reserve reserve;
    struct __NODE_RESERVE__ *next;
}Node_reserve;

struct financial
{
    char operation[64];
    int money;
    int student_id;
    struct date date;
};

struct food_delivery
{
    struct date date;
    int student_id;
    char meal_type[8];
    int hour;
    int minute;
    int self_id;
    int food_id;
};
// globals

struct date today;
int time_hour;
int time_min;
int today_weekday;
int time_now;

//functions
void welcome();
void operation(int *opt);
void getting_password(char *password);
void Exit();
void Register();
void Login(int *login_check,int *id_holder,char **type);
void after_login(int *login_end, int id_holder, char **type);
void after_login_s(int *login_end , int id_holder);
void after_login_p(int *login_end , int id_holder);
Node *new_node(struct user usr);
Node_food *new_node_food(struct food FOOD);
Node_self *new_node_self(struct self SELF); 
Node_poll *new_node_poll(struct poll POLL);
Node_meal_plan *new_node_meal_plan(struct meal_plan MEALPLAN);
Node_reserve *new_node_reserve(struct reserve reserve);
void add_node(Node **head ,Node *newNode);
void add_node_food(Node_food **head , Node_food *newNode);
void add_node_self(Node_self **head , Node_self *newNode);
void add_node_poll(Node_poll **head , Node_poll *newNode);
void add_node_meal_plan(Node_meal_plan **head , Node_meal_plan *newNode);
void add_node_reserve(Node_reserve **head , Node_reserve *newNode);
void print_list(Node *head);
void display_polls(Node_poll *head);
void delete_by_id(Node **head ,int id);
void delete_reservation_node(int self_id, Node_reserve **head , int id_holder , struct date date , char meal[]);
void delete_all(Node *head);
void delete_all_food(Node_food *head);
void delete_all_self(Node_self *head);
void delete_all_poll(Node_poll *head);
void delete_all_meal_plan(Node_meal_plan *head);
void delete_all_reserve(Node_reserve *head);
void write_file(Node *head);
void write_file_poll(Node_poll *head);
void write_delete_reservation(Node_reserve *head);
void write_file_change_count(Node_meal_plan *head_meal_plan);
void change_password(int id_holder);
void approve();
void change_node_pass(char new_password[] ,Node *head ,int id);
void print_unapproved(Node *head);
void change_node_approve_num(Node *head_approve , int id);
void change_student_pass();
void change_node_poll(Node_poll *head , int number , int op);
void change_node_meal_plan_count(Node_meal_plan *head_meal_plan , int self_id , int food_id);
void change_node_charge(Node *head , int id , int amount);
void remove_student();
void deactivating_student();
void change_node_active(Node *head ,int id);
void adding_user();
void define_self();
void define_food();
void define_meal_plan();
void charge_student_account();
void check_reservasion_details();
void personal_operation_report();
void general_report();
void add_news();
void add_poll();
void reserve(int id_holder);
void charge_account(int id_holder);
void send_charge(int id_holder);
void take_food(int id_holder);
int date_comparition(struct date tarikh1 , struct date tarikh2);
void check_news();
void vote();
int two_days__two_weeks(struct date tarikh1 , struct date tarikh2);
int finding_gender(int id_holder);
int finding_self_type(int self_id);
int find_price(int food_id);
int find_money_amount(int id_holder);
void change_node_money_reserve(Node *head_user , int id_holder , int price);
int check_duplicate_reservation(struct date tarikh , int id_holder , char meal[]);
void seeing_reserved_meal_plan(int id_holder);
int this_week_and_the_week_after(struct date tarikh,struct date mabda);
void cancel_reservation(int id_holder);
int between_hours_take_food(int today_hour , int today_min , int self_id , char meal[]);
void daily_reserve(int id_holder);
void returning_money(int id_holder ,int food_id);
int is_more_than_30(int time_now , int end_time);
void change_self(int id_holder);
void change_self_id(Node_reserve *head , int id_holder , int new_self_id , struct date reservation_date , char meal[]);
void write_file_self_id_change(Node_reserve *head_reserve);
void financial_report(int id_holder);
void write_file_financial(int student_id , int amount , char oprt[], struct date today);
void write_file_food_delivery(int student_id,int self_id,char meal_type[],struct date Date,int current_time_minute,int current_time_hour, int food_id);
void food_delivery_report(int id_holder);
int reserved_food_count_in_self(int self_id , char meal[] , struct date date , int food_id);
int count_total_food(struct date date , char meal[]);
int count_taken_food(int self_id , int food_id , struct date date);
int count_total_taken_food(struct date date,char meal_type[]);
void added_charge(int student_id,struct date start,struct date end);
void reserved_food(int student_id,struct date start,struct date end);
void taken_food(int student_id,struct date start,struct date end);
void canceled_reservation(int student_id,struct date start,struct date end);
int is_two_days_or_more(struct date today, struct date date);
int check_validation_of_selfid(int self_id , struct date date);
int check_food_validation(int food_id , char meal_type[] , int self_id , struct date date);
void return_the_food(int self_id,int food_id,struct date reservation);
void set_time();
void display_time();
int available_id_approve(Node *head_approve,int id_approve);

//main function
int main()
{
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    today.day = local_time->tm_mday;
    today.month = local_time->tm_mon + 1;
    today.year = local_time->tm_year + 1900;
    time_hour = local_time->tm_hour;
    time_min = local_time->tm_min;
    today_weekday = local_time->tm_wday + 1;
    time_now = time_hour*100 + time_min;
    char *Type[10];
    int opt , login_check = 0 , login_end = 1 , id_holder;
    while(1)
    {
        welcome();
        operation(&opt);
        switch (opt)
        {
            case 1:
            Register();
                break;
            
            case 2:
            login_check = 0;
            Login(&login_check , &id_holder,Type);
            if (login_check == 1)
            {
                login_end = 1;
                while (login_end == 1)
                {
                    after_login(&login_end,id_holder,Type);
                }
            }
                break;
            case 0:
            Exit();
            return 0;
                break;
            case 3:
            set_time();
                break;
            default:
                printf("\tinvalid\n");
                break;
        }
    }
}

void welcome()
{
    printf("\n\t\t\t\t---------- welcome to the project ----------\n");
}

void operation(int *opt)
{
    printf("\tchoose your operation :\n\t1.Register\n\t2.Login\n\t3.set-time\n\t0.Exit\n");
    scanf("%d",opt);

}

void getting_password(char *password)
{
    int p=0;
    do{
        password[p]=getch();
        if(password[p]!='\r'){
            printf("*");
        }
        p++;
    }while(password[p-1]!='\r');
    password[p-1]='\0';
    printf("\n");
}

void Register()
{
    struct user user1;
    struct user temp;
    printf("\tenter your name :\n");
    scanf(" %s",&(user1.name));
    printf("\tenter your last name :\n");
    scanf(" %s",&(user1.family));
    printf("\tenter your id :\n");
    scanf("%d",&(user1.id));
    printf("\tenter your password :\n");
    scanf(" %s",user1.password);
    printf("\tenter your country code :\n");
    scanf("%d",&(user1.national_id_code));
    printf("\tenter your birth date (2004-04-15 = 2004\\04\\15) :\n");
    scanf("%d-%d-%d",&(user1.date.year),&(user1.date.month),&(user1.date.day));
    printf("\tenter your gender (male or female) :\n");
    scanf(" %s",&(user1.gender));
    printf("\tenter type (student or admin) :\n");
    scanf(" %s",&(user1.type));
    user1.active = 1;
    user1.money = 0;
    user1.aprrove_number = 0;
    FILE *fptr = fopen("user.bin","rb");
    while (fread(&temp,sizeof(struct user),1,fptr))
    {
        if (temp.id == user1.id)
        {
            printf("\tpermission denied (the user has already registered!)\n");
            return;
        }
    }
    fclose(fptr);
    fptr = fopen("user.bin","ab");
    fwrite(&user1,sizeof(struct user),1,fptr);
    fclose(fptr);
    printf("\tuser successfully registered\n");
    return;
}

void Exit()
{
    printf("\tBYE BYE :) !");
}

void Login(int *login_check , int *id_holder , char **type)
{
    int id , check = 0;
    char password[30];
    struct user usr;
    printf("\tEnter your id: \n");
    scanf("%d",&id);
    *id_holder = id;
    while(1)
    {    
        printf("\tEnter your password: \n");
        getting_password(password);
        FILE *fptr = fopen("user.bin","rb");
        while (fread(&usr,sizeof(struct user),1,fptr))
        {
            if (usr.id == id)
            {
                check = 1;
                if (strcmp(usr.password,password) == 0)
                {
                    if (usr.aprrove_number == 1)
                    {
                        if(usr.active == 1)
                        {
                            strcpy(type,usr.type);
                            *login_check = 1;
                            fclose(fptr);
                            printf("\tlogin was successfull!\n");
                            return;
                        }
                        else
                        {
                            printf("\tyou have been disactivated!\n");
                            fclose(fptr);
                            return;
                        }
                    }
                    else
                    {
                        printf("\tyou should wait to be approved!\n");
                        fclose(fptr);
                        return;
                    }
                }
                else
                {
                    printf("\twrong password!\n");
                    fclose(fptr);
                    return;
                }
            }
        }
        if (check != 1)
        {
            printf("\tyou haven't registered !\n");
            return;
        }
        
    }
}        

void after_login(int *login_end, int id_holder,char **type)
{
    printf("\t\t\t---------- welocome to your page ----------\n");
    if (strcmp(type,"student") == 0)
    {
        after_login_s(login_end,id_holder);
        return;
    }
    else if (strcmp(type,"admin") == 0)
    {
        after_login_p(login_end,id_holder);
        return;
    }
    else
    {
        printf("\tinvalid type!\n");
    }
}

void after_login_s(int *login_end , int id_holder)
{
    int op;
    printf("\twhat do you want to do?\n\t(0.logout)\n\t(1.change password)\n\t(2.reserve)\n\t(3.take food)\n\t(4.charge account)\n");
    printf("\t(5.send charge)\n\t(6.see reserved meal plan)\n\t(7.cancel-reservation)\n\t(8.daily reserve)\n\t(9.define agent)\n");
    printf("\t(10.change self)\n\t(11.financial report)\n\t(12.food delivery report)\n\t(13.check news)\n\t(14.vote)\n\t(15.set-time)\n");
    scanf("%d",&op);
    if (op == 0)
    {
        *login_end = 0;
        return;
    }
    else if (op == 1)
    {
        change_password(id_holder);
    }
    else if (op == 2)
    {
        reserve(id_holder);
    }
    else if (op == 3)
    {
        take_food(id_holder);
    }
    else if (op == 4)
    {
        charge_account(id_holder);
    }
    else if (op == 5)
    {
        send_charge(id_holder);
    }
    else if(op == 6)
    {
        seeing_reserved_meal_plan(id_holder);
    }
    else if(op == 7)
    {
        cancel_reservation(id_holder);
    }
    else if(op == 8)
    {
        daily_reserve(id_holder);
    }
    else if(op == 9)
    {
        printf("\tsorry! this part isn't ready yet!\n");
    }
    else if(op == 10)
    {
        change_self(id_holder);
    }
    else if(op == 11)
    {
        financial_report(id_holder);
    }
    else if(op == 12)
    {
        food_delivery_report(id_holder);
    }
    else if (op == 13)
    {
        check_news();
    }
    else if (op == 14)
    {
        vote();
    }
    else if(op == 15)
    {
        set_time();
    }
    else
    {
        printf("\tinvalid operation\n");
    }
    
}

void after_login_p(int *login_end , int id_holder)
{
    int op;
    printf("\twhat do you want to do?\n\t(0.logout)\n\t(1.change password)\n\t(2.approve)\n\t(3.change student pass)\n\t(4.remove student)\n");
    printf("\t(5.deactiving a student)\n\t(6.add another user)\n\t(7.define-self)\n\t(8.define-food)\n\t(9.define-meal-plan)\n");
    printf("\t(10.charge-student-account)\n\t(11.check-reservasion-details)\n");
    printf("\t(12.personal operation report)\n\t(13.general report)\n\t(14.add news)\n\t(15.add poll)\n\t(16.set-time)\n");
    scanf("%d",&op);
    if (op == 0)
    {
        *login_end = 0;
        return;
    }
    else if (op == 1)
    {
        change_password(id_holder);
    }
    else if (op == 2)
    {
        approve();
    }
    else if (op == 3)
    {
        change_student_pass();
    }
    else if (op == 4)
    {
        remove_student();
    }
    else if (op == 5)
    {
        deactivating_student();
    }
    else if (op == 6)
    {
        adding_user();
    }
    else if (op == 7)
    {
        define_self();
    }
    else if (op == 8)
    {
        define_food();
    }
    else if (op == 9)
    {
        define_meal_plan();
    }
    else if (op == 10)
    {
        charge_student_account();
    }
    else if (op == 11)
    {
        check_reservasion_details();
    }
    else if (op == 12)
    {
        personal_operation_report();
    }
    else if (op == 13)
    {
        general_report();
    }
    else if (op == 14)
    {
        add_news();
    }
    else if (op == 15)
    {
        add_poll();
    }
    else if(op == 16)
    {
        set_time();
    }
    else
    {
        printf("\tinvalid operation\n");
    }
}

Node *new_node(struct user usr)
{
    Node *output = (Node*)malloc(sizeof(Node));
    output->usr = usr;
    output->next = NULL;
    return output;
}

void add_node(Node **head ,Node *newNode)
{
    Node *current = *head;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    
    current->next = newNode;
    return;
}

void delete_by_id(Node **head ,int id)
{
    Node *current = *head;
    if ((*head)->usr.id == id)
    {
        (*head) = (*head)->next;
        free(current);
        return;
    }
    while (current != NULL)
    {
       if (current->next->usr.id == id)
       {
        Node *hold = current->next;
        current->next=current->next->next;
        free(hold);
        return;
       }
       current = current->next;
    }
    printf("\tnot found!(id is invalid!)\n");
    return;
}

void delete_all(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *hold = current;
        current = current->next;
        free(hold);
    }
}

void print_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d --- %s\n",current->usr.id,current->usr.password);
        current = current->next;
    }
}

void write_file(Node *head)
{
    FILE *fp = fopen("user.bin","wb");
    Node *current = head;
    while (current != NULL)
    {
        fwrite(&current->usr,sizeof(struct user),1,fp);
        current = current->next;
    }
    fclose(fp);
    return ;
}

void change_password(int id_holder)
{
    char password[30],new_password[30];
    FILE *fptr;
    struct user usr;
    Node *head = NULL;
    while(1)
    {    
        printf("\tenter your current password:\n");
        getting_password(password);
        fptr = fopen("user.bin","rb"); 
        while (fread(&usr,sizeof(struct user),1,fptr))
        {
            add_node(&head,new_node(usr));
            if (usr.id == id_holder && strcmp(usr.password , password) == 0)
            {
                printf("\tenter your new password: \n");
                getting_password(new_password);
                change_node_pass(new_password ,head,id_holder);
            }
            else
            {
                printf("\twrong password!\n");
                delete_all(head);
                fclose(fptr);
                return;
            }
        }
        fclose(fptr);
        write_file(head);
        delete_all(head);
        printf("\tpassword changed successfully!\n");
        return;
    }
}

void approve()
{
    struct user usr;
    Node *head_approve = NULL;
    FILE *fptr = fopen("user.bin","rb");
    if(fptr == NULL)
    {
        printf("\tcouldn't open the file !\n");
        exit(2);
    }
    while (fread(&usr,sizeof(struct user),1,fptr))
    {
        if (usr.aprrove_number == 0)
        {
            add_node(&head_approve,new_node(usr));
        }
    }
    if (head_approve == NULL)
    {
        printf("\tno one is in the list!\n");
        fclose(fptr);
        delete_all(head_approve);
        return;
    }
    fclose(fptr);
    printf("\there is the list of unapproved personnels :\n");
    print_unapproved(head_approve);
    int flag = 1 , id_approve[8]={0} , check = 0,index = 0 , i = 0;
    delete_all(head_approve);
    head_approve = NULL;
    printf("\tenter the id(s) that you want to approve (press 0 to stop):\n");
    while (flag == 1)
    {
        scanf("%d",&id_approve[i]);
        if (id_approve[i++] == 0)
        {
            flag = 0;
            break;
        }
    }
    fptr = fopen("user.bin","rb");
    while(fread(&usr,sizeof(struct user),1,fptr))
        {
            add_node(&head_approve,new_node(usr));
        }
    fclose(fptr);
    if(head_approve == NULL)
    {
        delete_all(head_approve);
        return;
    }
    int g = 0;
    for (int j = 0; j < i; j++)
    {
        if(available_id_approve(head_approve,id_approve[j]) == 0)
        {
            continue;
        }
        change_node_approve_num(head_approve,id_approve[j]);
    }
    write_file(head_approve);
    delete_all(head_approve);
    printf("\tapprovement was successful!\n\n");
    return;
}

void change_node_pass(char new_password[] ,Node *head ,int id)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->usr.id == id)
        {
            strcpy(current->usr.password,new_password);
            return;
        }
        current = current->next;
    }
}

void print_unapproved(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("\t%d ------ %s\n",current->usr.id,current->usr.type);
        current = current->next;
    }
    return ;
}

void change_node_approve_num(Node *head_approve , int id)
{
    Node *current = head_approve;
    while (current != NULL)
    {
        if(current->usr.id == id)
        {
            current->usr.aprrove_number = 1;
            return;
        }
        current = current->next;
    }
}

void change_student_pass()
{
    int id_change_pass;
    char new_pass[30];
    struct user usr;
    FILE *fptr = fopen("user.bin","rb");
    if (fptr == NULL)
    {
        printf("\tcouldn't open the file\n");
        exit(1);
    }
    Node *head_CSP = NULL;
    printf("\tenter id of the student:\n");
    scanf("%d",&id_change_pass);
    printf("\tenter his/her new password:\n");
    scanf(" %s",&new_pass);
    while(fread(&usr,sizeof(struct user),1,fptr))
    {
        add_node(&head_CSP,new_node(usr));
        if (usr.id == id_change_pass)
        {
            change_node_pass(new_pass,head_CSP,id_change_pass);
        }
    }
    fclose(fptr);
    write_file(head_CSP);
    delete_all(head_CSP);
    printf("\tpassword changed successfully\n");
    return;
}

void remove_student()
{
    int id_remove ,confirm , check = 0;
    struct user usr;
    FILE *fptr = fopen("user.bin","rb");
    Node *head_remove = NULL;
    printf("\tenter id of the student that you want to remove:\n");
    scanf("%d",&id_remove);
    while (fread(&usr,sizeof(struct user),1,fptr))
    {
        if(usr.id == id_remove)
        {
            check = 1;
        }
        add_node(&head_remove,new_node(usr));
    }
    if(check == 0)
    {
        printf("\tpermission denied !(couldn't find the id)\n");
        delete_all(head_remove);
        fclose(fptr);
        return;
    }
    printf("\tare you sure you want to remove %d from the site?\n\t(1.yes)\n\t(2.no)\n",id_remove);
    scanf("%d",&confirm);
    if (confirm == 1)
    {
        delete_by_id(&head_remove,id_remove);
    }
    else // confirm == 0
    {
        delete_all(head_remove);
        fclose(fptr);
        return;
    }
    fclose(fptr);
    write_file(head_remove);
    delete_all(head_remove);
    printf("\tthe student was removed\n");
    return;
}

void deactivating_student()
{
    int id_deactivate;
    struct user usr;
    Node *head_deactive = NULL;
    FILE *fptr = fopen("user.bin","rb");
    printf("\tenter id of the student that you want to deactive:\n");
    scanf("%d",&id_deactivate);
    while (fread(&usr,sizeof(struct user),1,fptr))
    {
        add_node(&head_deactive,new_node(usr));
        if (usr.id == id_deactivate)
        {
            change_node_active(head_deactive,id_deactivate);
        }
    }
    fclose(fptr);
    write_file(head_deactive);
    delete_all(head_deactive);
    printf("\tstudent was deactivated!\n\n");
    return;
}

void change_node_active(Node *head ,int id)
{
    Node *current = head;
    while (current != NULL)
    {
        if(current->usr.id == id)
        {
            current->usr.active = 0;
            return;
        }
        current = current->next;
    }
}

void adding_user()
{
    struct user usr , temp;
    printf("\tenter type of the user (admin or student):\n");
    scanf(" %s",&(usr.type));
    printf("\tenter user's name :\n");
    scanf(" %s",&(usr.name));
    printf("\tenter user's last name :\n");
    scanf(" %s",&(usr.family));
    printf("\tenter user's gender (male or female):\n");
    scanf(" %s",&(usr.gender));
    printf("\tenter user's birth date (2004-04-15 = 2004\\04\\15):\n");
    scanf("%d-%d-%d",&(usr.date.year),&(usr.date.month),&(usr.date.day));
    printf("\tenter user's id :\n");
    scanf("%d",&(usr.id));
    printf("\tenter user's country code :\n");
    scanf("%d",&(usr.national_id_code));
    printf("\tenter user's password :\n");
    scanf(" %s",usr.password);
    usr.aprrove_number = 1;
    usr.active = 1;
    FILE *fptr = fopen("user.bin","rb");
    while (fread(&temp,sizeof(struct user),1,fptr))
    {
        if (temp.id == usr.id)
        {
            printf("\tpermission denied (the user has already registered!)\n");
            fclose(fptr);
            return;
        }
    }
    fclose(fptr);
    fptr = fopen("user.bin","ab");
    fwrite(&usr,sizeof(struct user),1,fptr);
    fclose(fptr);
    printf("\tuser was successfully added!\n");
    return;
}

void define_self()
{
    struct self slf;
    printf("\tenter the id of self :\n");
    scanf("%d",&(slf.id));
    printf("\tenter the name of the self :\n");
    scanf(" %s",&(slf.name));
    printf("\tenter the location of the self :\n");
    scanf(" %s",&(slf.location));
    printf("\tentre the capacity of self :\n");
    scanf("%d",&(slf.capacity));
    printf("\tenter type of the self (boyish or girlish) :\n");
    scanf(" %s",&(slf.type));
    printf("\tenter meals that are being served (lunch) or (dinner) or (both) :\n");
    scanf(" %s",&(slf.meal));
    printf("enter the time limitation for serving each meal (17:30 - 20:00  = 1730-2000) (if the self doesn't serve a meal, enter 0)\n");
    printf("\tlunch :\n");
    scanf("%d-%d",&(slf.lunch.start),&(slf.lunch.end));
    printf("\tdinner :\n");
    scanf("%d-%d",&(slf.dinner.start),&(slf.dinner.end));
    FILE *fptr = fopen("self.bin","ab");
    fwrite(&slf,sizeof(struct self),1,fptr);
    fclose(fptr);
    printf("\tnew self, successfully defined!\n\n");
}

void define_food()
{
    struct food ghaza;
    printf("\tenter id of the food :\n");
    scanf("%d",&(ghaza.id));
    printf("\tenter the name of the food :\n");
    scanf(" %s",&(ghaza.name));
    printf("\tenter type of the food (food or desert) :\n");
    scanf(" %s",&(ghaza.type));
    printf("\tenter price of the food :\n");
    scanf("%d",&(ghaza.price));
    FILE *fptr = fopen("food.bin","ab");
    fwrite(&ghaza,sizeof(struct food),1,fptr);
    fclose(fptr);
    printf("\tfood was successfully defined!\n\n");
}

void define_meal_plan()
{
    struct meal_plan plan;
    struct self self;
    struct food food;
    printf("\tenter self id :\n");
    scanf("%d",&(plan.self_id));
    printf("\tenter date (exp : 2004-05-12) :\n");
    scanf("%d-%d-%d",&(plan.tarikh.year),&(plan.tarikh.month),&(plan.tarikh.day));
    printf("\tenter type of the food (lunch or dinner) :\n");
    scanf(" %s",&(plan.type));
    printf("\tenter food id :\n");
    scanf("%d",&(plan.food_id));
    printf("\tenter the number of foods you want to have :\n");
    scanf("%d",&(plan.count));
    FILE *fptr1 = fopen("self.bin","rb") , *fptr2 = fopen("food.bin","rb") , *fptr3 = fopen("mealplan.bin","ab");
    while (fread(&self,sizeof(struct self),1,fptr1))
    {
        if (self.id == plan.self_id)
        {
            while (fread(&food,sizeof(struct food),1,fptr2))
            {
                if (food.id == plan.food_id)
                {
                    fwrite(&plan,sizeof(struct meal_plan),1,fptr3);
                    fclose(fptr1);
                    fclose(fptr2);
                    fclose(fptr3);
                    printf("\tplan successfully defined!\n");
                    return;
                }
            }  
        }
    }
    printf("\tnot found! (id of food or self doesn't exist)\n");
    return;
}

void charge_student_account()
{
    struct user student , temp;
    int amount , check = 0 , s_id;
    Node *head_charge = NULL;
    printf("\tenter student's id:\n");
    scanf("%d",&(student.id));
    s_id = student.id;
    printf("\tenter the amount of money you want to charge :\n");
    scanf("%d",&amount);
    FILE *fptr = fopen("user.bin","rb");
    while (fread(&temp,sizeof(struct user),1,fptr))
    {  
        add_node(&head_charge,new_node(temp));
        if (temp.id == student.id)
        {
            check = 1;
            change_node_charge(head_charge,temp.id,amount);
        } 
    }
    fclose(fptr);
    if(check == 1)
        write_file(head_charge);
    else
    {
        printf("\tnot found! (id not found)\n");
        delete_all(head_charge);
        return;
    }

    delete_all(head_charge);
    write_file_financial(s_id,amount,"charged by admin",today);
    printf("\tsuccessfully charged!\n");
    return;
}

void change_node_charge(Node *head , int id , int amount)
{
    Node *current = head;
    while (current != NULL)
    {
        if(current->usr.id == id)
        {
            current->usr.money += amount;
            return;
        }
        current = current->next;
    }
}

void check_reservasion_details()
{
    int self_id , food_id;
    struct date tarikh , today;
    char meal_type[8];
    printf("\tenter the date you want to check (exp : 2019-6-7) :\n");
    scanf("%d-%d-%d",&(tarikh.year),&(tarikh.month),&(tarikh.day));
    printf("\tenter type of the meal (lunch or dinner) :\n");
    scanf(" %s",&meal_type);
    printf("\tenter the self id :\n");
    scanf("%d",&self_id);
    printf("\tenter the food id :\n");
    scanf("%d",&food_id);
    if(date_comparition(today,tarikh) <= 0)
    {
        int total_count = count_total_food(tarikh,meal_type);
        if(total_count > 0)
            printf("\ttotal count of foods reserved in this date and for this meal : %d\n",total_count);
        else
        {
            printf("\tnothing has been  reserved !\n");
            return;
        }
        int count = reserved_food_count_in_self(self_id,meal_type,tarikh,food_id);
        if(count > 0)
        {
            printf("\tnumber of reserved food with the given information is : %d\n",count);
            return;
        }
        else
        {
            printf("\tnothing has been  reserved !\n");
            return;
        }
    }
    else
    {
        int total_taken = count_total_taken_food(tarikh,meal_type);
        if(total_taken > 0)
            printf("\ttotal count of foods taken in this date and for this meal : %d\n",total_taken);
        else
        {
            printf("\tnothing has been  reserved !\n");
            return;
        }
        int taken_food = count_taken_food(self_id,food_id,tarikh);
        if(taken_food > 0)
            printf("\tcount of taken food from this self : %d\n",taken_food);
        else
        {
            printf("\tno one has taken food from this self !\n");
            return;
        }
    }
}

void personal_operation_report()
{
    int student_id;
    struct date start , end;
    printf("\tenter student's id :\n");
    scanf("%d",&student_id);
    printf("\tenter the start date for time range (2012-3-4) :\n");
    scanf("%d-%d-%d",&(start.year),&(start.month),&(start.day));
    printf("\tenter the end date for time range (2012-3-4) :\n");
    scanf("%d-%d-%d",&(end.year),&(end.month),&(end.day));
    added_charge(student_id,start,end);
    reserved_food(student_id,start,end);
    taken_food(student_id,start,end);
    canceled_reservation(student_id,start,end);
    return;

}

void general_report()
{

}

void add_news()
{
    struct news news;
    printf("\tenter the title of the article you wanna add to news part :\n");
    scanf(" %[^\n]s",&(news.title));
    printf("\tenter the content of the article :\n");
    scanf(" %[^\n]s",&(news.context));
    printf("\tenter the end time of showing this article (exp : 2022-5-11) :\n");
    scanf("%d-%d-%d",&(news.end_date.year),&(news.end_date.month),&(news.end_date.day));
    FILE *fptr = fopen("news.bin","ab");
    fwrite(&news,sizeof(struct news),1,fptr);
    fclose(fptr);
    printf("\tnews was successfully added!\n");
    return;
}

void add_poll()
{
    struct poll poll;
    printf("\tenter the question of the poll :\n");
    scanf(" %[^\n]s",&(poll.question));
    printf("\tenter your text for first option :\n");
    scanf(" %[^\n]s",&(poll.op1_t));
    printf("\tenter your text for second option :\n");
    scanf(" %[^\n]s",&(poll.op2_t));
    printf("\tenter your text for third option :\n");
    scanf(" %[^\n]s",&(poll.op3_t));
    printf("\tenter your text for fourth option :\n");
    scanf(" %[^\n]s",&(poll.op4_t));
    poll.op1 = poll.op2 = poll.op3 = poll.op4 = 0;
    printf("\tenter the end date of poll (exp : 2022-4-11) :\n");
    scanf("%d-%d-%d",&(poll.end_date.year),&(poll.end_date.month),&(poll.end_date.day));
    FILE *fptr = fopen("poll.bin","ab");
    if (fptr == NULL)
    {
        printf("\tcouldn't open the file!\n");
        return;
    }
    
    fwrite(&poll,sizeof(struct poll),1,fptr);
    fclose(fptr);
    printf("\tpoll was successfully added to program!\n");
    return;
}

void reserve(int id_holder)
{
    while(1)
    {
        int self_id , gender_user = finding_gender(id_holder) , food_id;
        struct meal_plan MealPlan;
        struct user student;
        struct date date;
        char meal[8];
        FILE *fptr_MealPlan = fopen("mealplan.bin","rb");
        if(fptr_MealPlan == NULL)
        {
            printf("\tcouldn't open the file\n");
            exit(5);
        }
        Node_meal_plan *head_meal_plan = NULL;
        printf("\there is the list of selfs that you can reserve from :\n\n");
        while (fread(&MealPlan,sizeof(struct meal_plan),1,fptr_MealPlan))
        {
            int self_type = finding_self_type(MealPlan.self_id);
            add_node_meal_plan(&head_meal_plan,new_node_meal_plan(MealPlan));
            if(two_days__two_weeks(today,MealPlan.tarikh) == 1)
            {
                if((gender_user == 1 && self_type == 1)||(gender_user == 2 && self_type == 2))
                {
                    printf("\tself id : %d\n",MealPlan.self_id);
                    printf("\ttype of meal : %s\n",MealPlan.type);
                    printf("\tfood id : %d\n",MealPlan.food_id);
                    printf("\tfood remaining : %d\n",MealPlan.count);
                    printf("\tdate of meal : %d-%d-%d\n\n",MealPlan.tarikh.year,MealPlan.tarikh.month,MealPlan.tarikh.day);
                }
            }
        }
        fclose(fptr_MealPlan);
        printf("\tenter the self id :\n");
        scanf("%d",&self_id);
        printf("\tenter the date of reservatoin (2015-12-3) :\n");
        scanf("%d-%d-%d",&(date.year),&(date.month),&(date.day));
        if(check_validation_of_selfid(self_id,date) == 0 || finding_self_type(self_id) != finding_gender(id_holder))
        {
            printf("\tyou can't reserve from this self!(self_id is invalid or gender of the self is not suitable for you)\n");
            delete_all_meal_plan(head_meal_plan);
            return;
        }
        if(is_two_days_or_more(today,date) == 0)
        {
            printf("\tyou can't reserve for this date, now!\n");
            delete_all_meal_plan(head_meal_plan);
            return;
        }
        printf("\tenter the meal you want to reserve for :\n");
        scanf(" %s", &meal);
        printf("\tenter the food id :\n");
        scanf("%d",&food_id);
        if(check_food_validation(food_id,meal,self_id,date) == 0)
        {
            printf("\tfood is not available in meal plan !\n");
            delete_all_meal_plan(head_meal_plan);
            return;
        }
        int price = find_price(food_id) , money = find_money_amount(id_holder) , check_duplicates = check_duplicate_reservation(date,id_holder,meal);
        Node *head_user = NULL;
        if(check_duplicates == -1)
        {
            printf("\tyou have reserved a meal for this day!\n");
            delete_all_meal_plan(head_meal_plan);
            return;
        }
        FILE *fptr_user = fopen("user.bin","rb") , *fptr_reserve = fopen("reserve.bin","ab");
        while (fread(&student,sizeof(struct user),1,fptr_user))
        {
            add_node(&head_user,new_node(student));
        }
        fclose(fptr_user);
        if (money >= price)
        {
            struct reserve reserve;
            reserve.food_id = food_id;
            reserve.self_id = self_id;
            reserve.student_id = id_holder;
            reserve.tarikh_reserve = date;
            strcpy(reserve.meal,meal);
            fwrite(&reserve,sizeof(struct reserve),1,fptr_reserve);
            change_node_meal_plan_count(head_meal_plan,self_id,food_id);
            write_file_change_count(head_meal_plan);
            change_node_money_reserve(head_user,id_holder,price);
            write_file(head_user);
            delete_all(head_user);
            delete_all_meal_plan(head_meal_plan);
            fclose(fptr_reserve);
            write_file_financial(id_holder,-1*price,"reserving",today);
            printf("\tsuccessfully reserved!\n");
            return;
        }
        else
        {
            int opt;
            printf("\tyou don't have enough money in your account, enter your choice \n\t(1.charge account) (0.exit)\n");
            scanf("%d",&opt);
            if(opt == 1)
            {
                delete_all(head_user);
                delete_all_meal_plan(head_meal_plan);
                fclose(fptr_reserve);
                charge_account(id_holder);
            }
            else
            {
                delete_all(head_user);
                delete_all_meal_plan(head_meal_plan);
                fclose(fptr_reserve);
                return;
            }  
        }
    }
}

void charge_account(int id_holder)
{
    struct user usr;
    FILE *fptr1 = fopen("user.bin","rb");
    int amount , num ;
    char card_num[16];
    Node *head_charge = NULL;
    while(fread(&usr,sizeof(struct user),1,fptr1))
    {
        add_node(&head_charge,new_node(usr));
        if (id_holder == usr.id)
        {
            printf("\tyour credit is currently %d\n",usr.money);
            printf("\tenter the amount of money you want to add to your account :\n");
            scanf("%d",&amount);
            printf("\tenter your debit card number :\n");
            scanf(" %s",&card_num);
            printf("\tenter your PIN\n");
            scanf("%d",&num);
            change_node_charge(head_charge,id_holder,amount);
            num = amount + usr.money;
        }
    }
    fclose(fptr1);
    write_file(head_charge);
    delete_all(head_charge);
    write_file_financial(id_holder,amount,"charged by your self",today);
    printf("\tcharging was successfull! your credit is %d\n",num);
    return;
}

void send_charge(int id_holder)
{
    int id ,check = 0 ,amount;
    char name[30];
    struct user usr;
    printf("\nenter the id of the person you want to send charge to :\t");
    scanf("%d",&id);
    FILE *fptr = fopen("user.bin","rb");
    Node *head_send_charge = NULL;
    while (fread(&usr,sizeof(struct user),1,fptr))
    {
        add_node(&head_send_charge,new_node(usr));
        if (usr.id == id)
        {
            printf("\tenter the name (first name) of the chosen student :\n");
            scanf(" %s",&name);
            if (strcmpi(usr.name,name) == 0)
            {
                check = 1;
                printf("\tenter the amount of money you want to send :\n");
                scanf("%d",&amount);
                fclose(fptr);
                change_node_charge(head_send_charge,id,amount);
            }
            else
            {
                printf("\tnot found ! (wrong name)\n");
                delete_all(head_send_charge);
                fclose(fptr);
                return;
            }
            
        }
        
    }
    if (check != 1)
    {
        printf("\tnot found!(wrong id)\n");
        delete_all(head_send_charge);
        fclose(fptr);
        return;
    }
    Node *current = head_send_charge;
    while (current != NULL)
    {
        if (current->usr.id == id_holder)
        {
            current->usr.money -= amount;
        }
        current = current->next;
    }
    write_file(head_send_charge);
    delete_all(head_send_charge);
    write_file_financial(id_holder,-1*amount,"send charge",today);
    write_file_financial(id,amount,"sent by other students",today);
    printf("\tcharge successfully sent to %s\n",name);
    return;
}

Node_food *new_node_food(struct food FOOD)
{
    Node_food *output = (Node_food*)malloc(sizeof(Node_food));
    output->FOOD = FOOD;
    output->next = NULL;
    return output;
}

Node_self *new_node_self(struct self SELF)
{
    Node_self *output = (Node_self *)malloc(sizeof(Node_self));
    output->SELF = SELF;
    output->next = NULL;
    return output;
}

void add_node_food(Node_food **head , Node_food *newNode)
{
    Node_food *current = *head;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    
    current->next = newNode;
    return;
}

void add_node_self(Node_self **head , Node_self *newNode)
{
    Node_self *current = *head;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    
    current->next = newNode;
    return;
}

void delete_all_food(Node_food *head)
{
    Node_food *current = head;
    while (current != NULL)
    {
        Node_food *hold = current;
        current = current->next;
        free(hold);
    }
    return;
}

void delete_all_self(Node_self *head)
{
    Node_self *current = head;
    while (current != NULL)
    {
        Node_self *hold = current;
        current = current->next;
        free(hold);
    }
    return ;
}

int date_comparition(struct date tarikh1 , struct date tarikh2)
{
    if (tarikh1.year > tarikh2.year)
    {
        return 1;
    }
    else if (tarikh1.year < tarikh2.year)
    {
        return -1;
    }
    else if(tarikh1.year ==tarikh2.year && tarikh1.month > tarikh2.month)
    {
        return 1;
    }
    else if(tarikh1.year ==tarikh2.year && tarikh1.month < tarikh2.month)
    {
        return -1;
    }
    else if(tarikh1.year ==tarikh2.year && tarikh1.month == tarikh2.month && tarikh1.day > tarikh2.day)
    {
        return 1;
    }
    else if(tarikh1.year ==tarikh2.year && tarikh1.month == tarikh2.month && tarikh1.day < tarikh2.day)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void check_news()
{
    int check = 0;
    struct news news;
    FILE *fptr = fopen("news.bin","rb");
    printf("\t\t\t---------- welocome to the news part ----------\n");
    while (fread(&news,sizeof(struct news),1,fptr))
    {
        if (date_comparition(news.end_date,today) > 0)
        {
            check = 1;
            printf("\ttitle :\n\t");
            puts(news.title);
            printf("\n\tcontent :\n\t");
            puts(news.context);
            printf("\n");
        }
    }
    if(check != 1)
    {
        printf("\tnot found! (there is no news for now)\n");
    }
    fclose(fptr);
}

void vote()
{
    struct poll poll;
    Node_poll *head_poll = NULL;
    int op , number , check = 0;
    FILE *fptr = fopen("poll.bin","rb");
    if (fptr == NULL)
    {
        printf("\tcouldn't open file!\n");
        return ;
    }
    printf("\t\t\t---------- welocome to the polls part ----------\n");
    while (fread(&poll,sizeof(struct poll),1,fptr))
    {
        if(date_comparition(poll.end_date,today) > 0)
        {
            check = 1;
            add_node_poll(&head_poll,new_node_poll(poll));
        }
    }
    fclose(fptr);
    if (check != 1)
    {
        printf("\tnot found ! (no poll is on the website right now !)\n");
        delete_all_poll(head_poll);
        return;
    }
    printf("\there is the list of polls you can attend :\n");
    display_polls(head_poll);
    printf("\tenter the number of the poll you want to attend in :\n");
    scanf("%d",&number);
    printf("\twhich option you want to vote for ?\n\t(1.op1) (2.op2) (3.op3) (4.op4)\n");
    scanf("%d",&op);
    change_node_poll(head_poll,number,op);
    write_file_poll(head_poll);
    delete_all_poll(head_poll);
    printf("\tvoting was successfull!\n");
    return;

}

Node_poll *new_node_poll(struct poll POLL)
{
    Node_poll *output = (Node_poll*)malloc(sizeof(Node_poll));
    output->poll = POLL;
    output->next = NULL;
    return output;
}

void add_node_poll(Node_poll **head , Node_poll *newNode)
{
    Node_poll *current = *head;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    
    current->next = newNode;
    return;
}

void delete_all_poll(Node_poll *head)
{
    Node_poll *current = head;
    while (current != NULL)
    {
        Node_poll *hold = current;
        current = current->next;
        free(hold);
    }   
    return;
}

void display_polls(Node_poll *head)
{
    Node_poll *current = head;
    int number = 1;
    while (current != NULL)
    {
        printf("\tpoll %d :\n",number);
        printf("\t%s\n",current->poll.question);
        printf("\top1 :\n");
        printf("\t%s\n",current->poll.op1_t);
        printf("\top2 :\n");
        printf("\t%s\n",current->poll.op2_t);
        printf("\top3 :\n");
        printf("\t%s\n",current->poll.op3_t);
        printf("\top4 :\n");
        printf("\t%s\n",current->poll.op4_t);
        printf("\n\tothers have voted like this :\n\top1 : %d | op2 : %d | op3 : %d | op4 : %d\n",current->poll.op1,current->poll.op2,current->poll.op3,current->poll.op4);
        number++;
        current = current->next;
    }
    
}

void change_node_poll(Node_poll *head , int number , int op)
{
    Node_poll *current = head;
    int counter = 1;
    while (counter != number)
    {
        current = current->next;
        counter += 1;
    }
    if (current == NULL)
    {
        printf("\twrong number!\n");
        return;
    }
    switch (op)
    {
    case 1:
        current->poll.op1 += 1;
        break;
    case 2:
        current->poll.op2 += 1;
        break;

    case 3:
        current->poll.op3 += 1;
        break;

    case 4:
        current->poll.op4 += 1;
        break;
    
    default:
    printf("\twrong operation!\n");
        break;
    }
    return ;
}

void write_file_poll(Node_poll *head)
{
    Node_poll *current = head;
    FILE *fptr = fopen("poll.bin","wb");
    while (current != NULL)
    {
        fwrite(&current->poll,sizeof(struct poll),1,fptr);
        current = current->next;
    }
    fclose(fptr);
    return;
}

void take_food(int id_holder)
{
    int self_id;
    struct date reservation_date;
    char meal[8];
    struct reserve reserve;
    printf("\tenter the self id :\n");
    scanf("%d",&self_id);
    printf("\tenter the date of reservatoin (2012-4-5) :\n");
    scanf("%d-%d-%d",&(reservation_date.year),&(reservation_date.month),&(reservation_date.day));
    if(date_comparition(today,reservation_date) != 0)
    {
        printf("\tyou can't get this day's food now!\n");
        return;
    }
    printf("\tenter type of the meal (dinner or lunch) :\n");
    scanf(" %s",&meal);
    FILE *fptr = fopen("reserve.bin","rb");
    FILE *fptr_take_food = fopen("takefood.bin","ab");
    while (fread(&reserve,sizeof(struct reserve),1,fptr))
    {
        if (reserve.student_id == id_holder && date_comparition(reservation_date,reserve.tarikh_reserve) == 0 && strcmp(meal,reserve.meal) == 0)
        {  
            if(between_hours_take_food(time_hour,time_min,self_id,meal) == 1)
            {
                fclose(fptr);
                fwrite(&reserve,sizeof(struct reserve),1,fptr_take_food);
                fclose(fptr_take_food);
                write_file_food_delivery(id_holder,self_id,meal,reservation_date,time_min,time_hour,reserve.food_id);
                printf("\tfood was successfully given to you !\n");
                return;
            }
            else
            {
                fclose(fptr);
                fclose(fptr_take_food);
                printf("\ttime of taking food hasn't arrived yet, you should wait!\n");
                return;
            }
        }
    }
    fclose(fptr);
    fclose(fptr_take_food);
    printf("\tsomething is wrong about the information you gave us about your reservation, please try again and be careful !\n");
    return;
}

Node_meal_plan *new_node_meal_plan(struct meal_plan MEALPLAN)
{
    Node_meal_plan *output = (Node_meal_plan *)malloc(sizeof(Node_meal_plan));
    output->MEALPLAN = MEALPLAN;
    output->next = NULL;
    return output;    
}

void add_node_meal_plan(Node_meal_plan **head , Node_meal_plan *newNode)
{
    Node_meal_plan *current = (*head);
    if ((*head) == NULL)
    {
        (*head) = newNode;
        return;
    }
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
    return;
}

void delete_all_meal_plan(Node_meal_plan *head)
{
    Node_meal_plan *current = head;
    while (current != NULL)
    {
        Node_meal_plan *hold = current;
        current = current->next;
        free(hold);
    }   
    return;
}

int two_days__two_weeks(struct date tarikh1 , struct date end_time)
{
    int sum1 = 0 , sum2 = 0;
    sum1 += (tarikh1.year-1900)*366;
    sum2 += (end_time.year-1900)*366;
    if (tarikh1.month > 6)
        sum1 += tarikh1.month*30;
    if(tarikh1.month <= 6)
        sum1 += tarikh1.month*31;
    if (end_time.month > 6)
        sum2 += end_time.month*30;
    if(end_time.month <= 6)
        sum2 += end_time.month*31;
    
    sum1 += tarikh1.day;
    sum2 += end_time.day;
    if (sum2 - sum1 >= 2 && sum2-sum1 <= 14)
        return 1;
    else
        return -1;
}

int finding_gender(int id_holder)
{
    FILE *fptr = fopen("user.bin","rb");
    struct user usr;
    while (fread(&usr,sizeof(struct user),1,fptr))
    {
        if (usr.id == id_holder) 
        {
            if(strcmp(usr.gender,"male") == 0)
            {
                fclose(fptr);
                return 1;
            }
            if(strcmp(usr.gender,"female") == 0)
            {
                fclose(fptr);
                return 2;
            }
        }
    }
}

int finding_self_type(int self_id)
{
    FILE *fptr = fopen("self.bin","rb");
    struct self SELF;
    while (fread(&SELF,sizeof(struct self),1,fptr))
    {
        if (SELF.id == self_id)
        {
            if(strcmp(SELF.type,"boyish") == 0)
            {
                fclose(fptr);
                return 1;
            }
            if(strcmp(SELF.type,"girlish") == 0)
            {
                fclose(fptr);
                return 2;
            }
        }
    }
}

int find_price(int food_id)
{
    FILE *fptr = fopen("food.bin","rb");
    struct food FOOD;
    int food_price;
    while (fread(&FOOD,sizeof(struct food),1,fptr))
    {
        if (FOOD.id == food_id)
        {
            food_price = FOOD.price;
        }
    }
    fclose(fptr);
    return FOOD.price;
}

int find_money_amount(int id_holder)
{
    FILE *fptr = fopen("user.bin","rb");
    int user_money;
    struct user user;
    while(fread(&user,sizeof(struct user),1,fptr))
    {
        if (user.id == id_holder)
        {
            user_money = user.money;
        }
    }
    fclose(fptr);
    return user_money;
}

void change_node_money_reserve(Node *head_user , int id_holder , int price)
{
    Node* current = head_user;
    while (current != NULL)
    {
        if (current->usr.id == id_holder)
        {
            current->usr.money -= price;
            return;
        }
        current = current->next;
    }
}

int check_duplicate_reservation(struct date tarikh , int id_holder , char meal[])
{
    FILE *fptr = fopen("reserve.bin","rb");
    struct reserve reservation;
    while (fread(&reservation,sizeof(struct reserve),1,fptr))
    {
        if (reservation.student_id == id_holder && date_comparition(reservation.tarikh_reserve , tarikh) == 0 && strcmp(meal,reservation.meal) == 0)
        {
            return -1;
        }
    }
    return 1;
}

void seeing_reserved_meal_plan(int id_holder)
{
    FILE *fptr_reserve = fopen("reserve.bin","rb");
    struct reserve reserve;
    printf("\tthese are your reservation:\n");
    while (fread(&reserve,sizeof(struct reserve),1,fptr_reserve))
    {
        if(reserve.student_id == id_holder && this_week_and_the_week_after(today,reserve.tarikh_reserve) )
        {
            printf("\tself id : %d\n",reserve.self_id);
            printf("\tfood id : %d\n",reserve.food_id);
            printf("\tmeal : %s\n",reserve.meal);
            printf("\tdate of reserve : %d-%d-%d\n",reserve.tarikh_reserve.year,reserve.tarikh_reserve.month,reserve.tarikh_reserve.day);
        }
    }
    fclose(fptr_reserve);
    return;
}

int this_week_and_the_week_after(struct date tarikh,struct date mabda)
{
    int sum1 = 0 , sum2 = 0;
    sum1 += (tarikh.year - 1900)*366;
    sum2 += (mabda.year -1900)*366;
    if(tarikh.month > 6)
    {
        sum1 += tarikh.month * 30;
    }
    if (tarikh.month <= 6)
    {
        sum1 += tarikh.month * 31;
    }
    if (mabda.month > 6)
    {
        sum2 += mabda.month * 30;
    }
    if(mabda.month <= 6)
    {
        sum2 += mabda.month * 31;
    }
    if(sum2 >= sum1 && sum2 - sum1 <= 14)
        return 1;
    else
        return 0;
}

int between_hours_take_food(int today_hour , int today_min , int self_id , char meal[])
{
    struct self Self;
    int meal_start , meal_end;
    FILE *fptr_self = fopen("self.bin","rb");
    while (fread(&Self,sizeof(struct self),1,fptr_self))
    {
        if (Self.id == self_id)
        {
            if(strcmp(meal,"lunch") == 0)
            {
                meal_start = Self.lunch.start;
                meal_end = Self.lunch.end;
            }
            if (strcmp(meal,"dinner") == 0)
            {
                meal_start = Self.dinner.start;
                meal_end = Self.dinner.end;
            }   
        }
    }
    fclose(fptr_self);
    int t = (today_hour*100) + today_min;
    if (t >= meal_start && t <= meal_end)
    {
        return 1;
    }
    return 0;
}

void cancel_reservation(int id_holder)
{
    struct date reservation;
    char meal[8];
    int check = 0 , self_id , food_id;
    printf("\tenter reservation date (2012-3-4) :\n");
    scanf("%d-%d-%d",&(reservation.year),&(reservation.month),&(reservation.day));
    printf("\tenter type of the meal (lunch or dinner) :\n");
    scanf(" %s",&meal);
    struct self self;
    struct reserve reserve;
    FILE *fptr_reserve = fopen("reserve.bin","rb");
    if(fptr_reserve == NULL)
    {
        printf("\tcouldn't open the file\n");
        exit(5);
    }
    Node_reserve *head_reserve = NULL;
    struct date hold;
    while (fread(&reserve,sizeof(struct reserve),1,fptr_reserve))
    {
        add_node_reserve(&head_reserve,new_node_reserve(reserve));
        if(date_comparition(reserve.tarikh_reserve,reservation) == 0 && reserve.student_id == id_holder && strcmp(meal,reserve.meal) == 0)
        {
            check = 1;
            self_id = reserve.self_id;
            food_id = reserve.food_id;
        }
    }
    fclose(fptr_reserve);
    if(check != 1)
    {
        printf("\tcouldn't find a reservation with these information!\n");
        delete_all_reserve(head_reserve);
        return;
    }
    FILE *fptr_self = fopen("self.bin", "rb");
    if(fptr_self == NULL)
    {
        printf("\tcouldn't open the file\n");
        delete_all(head_reserve);
        exit(5);
    }
    int self_end , self_start;
    while (fread(&self,sizeof(struct self),1,fptr_self))
    {
        if(self_id == self.id)
        {
            if(strcmp(meal,"lunch") == 0)
            {
                self_start = self.lunch.start;
                self_end = self.lunch.end;
            }
            if(strcmp(meal,"dinner") == 0)
            {
                self_start = self.dinner.start;
                self_end = self.dinner.end;
            }
        }
    }
    fclose(fptr_self);
    if((date_comparition(today , reservation) == 0 && self_start - time_now >= 100)|| date_comparition(today , reservation) < 0)
    {
        delete_reservation_node(self_id ,&head_reserve,id_holder,reservation,meal);
        write_delete_reservation(head_reserve);
        delete_all_reserve(head_reserve);
        returning_money(id_holder,food_id);
        FILE *fptr_food = fopen("food.bin","rb");
        if(fptr_food == NULL)
        {
            printf("\tcouldn't open the file\n");
            exit(5);
        }
        struct food food;
        int price;
        while (fread(&food,sizeof(struct food),1,fptr_food))
        {
            if (food.id == food_id)
            {
                price = food.price;   
            }
        }
        fclose(fptr_food);
        write_file_financial(id_holder,(9*price)/10,"canceling reservation",today);
        return_the_food(self_id,food_id,reservation);
        printf("\treservation successfully canceled !\n");
        return;
    }
    else
    {
        printf("\tyou can't cancel your reservatoin !\n");
        delete_all_reserve(head_reserve);
        return;
    }
}

Node_reserve *new_node_reserve(struct reserve reserve)
{
    Node_reserve *output = (Node_reserve *)malloc(sizeof(Node_reserve));
    output->reserve = reserve;
    output->next = NULL;
    return output;
}

void add_node_reserve(Node_reserve **head , Node_reserve *newNode)
{
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node_reserve *current = *head;
    while (current->next != NULL)
        current = current->next;
    
    current->next = newNode;
    return;
}

void delete_all_reserve(Node_reserve *head)
{
    Node_reserve *current = head;
    while (current != NULL)
    {
        Node_reserve *hold = current;
        current = current->next;
        free(hold);
    }   
    return;
}

void delete_reservation_node(int self_id, Node_reserve **head , int id_holder , struct date date , char meal_type[])
{
    Node_reserve *current = *head , *hold = NULL;
    if((*head)->reserve.self_id == self_id && (*head)->reserve.student_id == id_holder && strcmp(meal_type,(*head)->reserve.meal) == 0 && date_comparition(date,(*head)->reserve.tarikh_reserve) == 0)
    {
        *head = (*head)->next;
        free(current);
        return ;
    }
    while(current != NULL)
    {
        if(current->next->reserve.self_id == self_id && current->next->reserve.student_id == id_holder && strcmp(meal_type,current->next->reserve.meal) == 0 && date_comparition(date,current->next->reserve.tarikh_reserve) == 0)
        {
            hold = current->next;
            current->next = current->next->next;
            free(hold);
        }
        current = current->next;
    }
    return;
}

void write_delete_reservation(Node_reserve *head)
{
    Node_reserve *current = head;
    FILE *fptr = fopen("reserve.bin","wb");
    while (current != NULL)
    {
        fwrite(&current->reserve,sizeof(struct reserve),1,fptr);
        current = current->next;
    }
    fclose(fptr);
    return;
}

void returning_money(int id_holder ,int food_id)
{
    FILE *fptr = fopen("food.bin","rb");
    struct food food;
    int price;
    while (fread(&food,sizeof(struct food),1,fptr))
    {
        if (food.id == food_id)
        {
            price = food.price;   
        }
    }
    fclose(fptr);
    fptr = fopen("user.bin","rb");
    struct user user;
    Node *head = NULL;
    while(fread(&user,sizeof(struct user),1,fptr))
    {
        add_node(&head,new_node(user));
    }
    fclose(fptr);
    change_node_charge(head,id_holder,((9*price)/10));
    write_file(head);
    delete_all(head);
    return;
}

void daily_reserve(int id_holder)
{
    while(1)
    {
        int self_id , food_id , check = 0 , price , count = 1 , dinner_start , dinner_end , lunch_start, lunch_end;
        printf("\tenter self id :\n");
        scanf("%d",&self_id);
        printf("\tenter food id :\n");
        scanf("%d",&food_id);
        struct meal_plan MEALPLAN;
        Node_meal_plan *head_meal_plan = NULL;
        FILE *fptr_meal_plan = fopen("mealplan.bin","rb");
        if(fptr_meal_plan == NULL)
        {
            printf("\terror openeing the file\n");
            exit(5);
        }
        while (fread(&MEALPLAN,sizeof(struct meal_plan),1,fptr_meal_plan))
        {
            add_node_meal_plan(&head_meal_plan,new_node_meal_plan(MEALPLAN));
            if(MEALPLAN.self_id == self_id && MEALPLAN.food_id == food_id)
            {
                check = 1;
                count = MEALPLAN.count;
            }
        }
        fclose(fptr_meal_plan);
        if(check != 1)
        {
            printf("\tnot found!(food or self id isn't correct)\n");
            return;
        }
        if(count <= 0)
        {
            printf("\twe are out of food !\n");
            return;
        }
        struct self self;
        FILE *fptr_self = fopen("self.bin","rb");
        while (fread(&self,sizeof(struct self),1,fptr_self))
        {
            if(self.id == self_id)
            {
                dinner_start = self.dinner.start;
                dinner_end = self.dinner.end;
                lunch_start = self.lunch.start;
                lunch_end = self.lunch.end;
            }
        }
        fclose(fptr_self);
        char meal[8];
        if(time_now >= lunch_start && time_now <= lunch_end)
        {   
            strcpy(meal,"lunch");
            printf("%d\n",is_more_than_30(time_now,lunch_end));
            if(is_more_than_30(time_now,lunch_end) == 0)
            {
                delete_all_meal_plan(head_meal_plan);
                printf("\tyou can't daily reserve now !\n");
                return;
            }
        }
        else if(time_now >= dinner_start && time_now <= dinner_end)
        {
            strcpy(meal,"dinner");
            if(is_more_than_30(time_now,lunch_end) == 0)
            {
                delete_all_meal_plan(head_meal_plan);
                printf("\tyou can't daily reserve now !\n");
                return; 
            }
        }
        else
        {
            delete_all_meal_plan(head_meal_plan);
            printf("\tyou can't daily reserve now!\n");
            return;
        }
        if(check_duplicate_reservation(today,id_holder,meal) == -1)
        {
            delete_all_meal_plan(head_meal_plan);
            printf("\tyou have a reservation today!\n");
            return;
        }
        FILE *fptr_food = fopen("food.bin","rb");
        struct food food;
        while (fread(&food,sizeof(struct food),1,fptr_food))
        {
            if(food.id == food_id)
            {
                price = 2*(food.price);
            }
        }
        Node *head_user = NULL;
        struct user user;
        FILE *fptr_user = fopen("user.bin","rb");
        while(fread(&user,sizeof(user),1,fptr_user))
        {
            add_node(&head_user,new_node(user));
            if(user.id == id_holder && user.money < price)
            {
                check = 5;
            }
        }
        fclose(fptr_user);
        if(check == 5)
        {
            int opt;
            printf("\tyou don't have enough money in your account, enter your choice \n\t(1.charge account) (0.exit)\n");
            scanf("%d",&opt);
            if(opt == 1)
            {
                delete_all(head_user);
                delete_all_meal_plan(head_meal_plan);
                charge_account(id_holder);
            }
            else
            {
                delete_all(head_user);
                delete_all_meal_plan(head_meal_plan);
                return;
            }
        }
        change_node_money_reserve(head_user,id_holder,price);
        write_file(head_user);
        change_node_meal_plan_count(head_meal_plan,self_id,food_id);
        write_file_change_count(head_meal_plan);
        delete_all(head_user);
        delete_all_meal_plan(head_meal_plan);
        FILE *fptr_reserve = fopen("reserve.bin","ab");
        struct reserve reserve;
        reserve.food_id = food_id;
        reserve.student_id = id_holder;
        reserve.self_id = self_id;
        strcpy(reserve.meal,meal);
        reserve.tarikh_reserve = today;
        fwrite(&reserve,sizeof(struct reserve),1,fptr_reserve);
        fclose(fptr_reserve);
        write_file_financial(id_holder,-1*price,"daily reserve",today);
        printf("\tsuccessfully reserved!\n");
        return;
    }
}

void change_node_meal_plan_count(Node_meal_plan *head_meal_plan , int self_id , int food_id)
{
    Node_meal_plan *current = head_meal_plan;
    while (current != NULL)
    {
        if(current->MEALPLAN.self_id == self_id && current->MEALPLAN.food_id == food_id)
        {
            current->MEALPLAN.count -= 1;
        }
        current = current->next;
    }
}

void write_file_change_count(Node_meal_plan* head_meal_plan)
{
    Node_meal_plan *current = head_meal_plan;
    FILE *fptr = fopen("mealplan.bin","wb");
    while (current != NULL)
    {
        fwrite(&current->MEALPLAN,sizeof(struct meal_plan),1,fptr);
        current = current->next;
    }
    fclose(fptr);
    return;
}

int is_more_than_30(int time_now , int end_time)
{
    int time_now_hour = (time_now)-(time_now % 100)/100 , time_now_min = time_now % 100 , end_time_hour = (end_time)-(end_time % 100)/100 , end_time_min = end_time % 100;
    if((end_time_hour*60 + end_time_min) - (time_now_hour*60 + time_now_min) >= 30)
        return 1;
    else
        return 0;
}

void change_self(int id_holder)
{
    struct date date_of_reserve;
    char meal_type[8];
    int new_self_id , reserve_check = 0, self_check = 0;
    printf("\tenter date of reserve (2004-4-5) :\n");
    scanf("%d-%d-%d",&(date_of_reserve.year),&(date_of_reserve.month),&(date_of_reserve.day));
    printf("\tenter meal type (dinner or lunch) :\n");
    scanf(" %s",&meal_type);
    printf("\tenter the new self id :\n");
    scanf("%d",&new_self_id);
    FILE *fptr_reserve = fopen("reserve.bin","rb") , *fptr_self = fopen("self.bin","rb");
    struct self self;
    while(fread(&self,sizeof(struct self),1,fptr_self))
    {
        if(self.id == new_self_id)
        {
            self_check = 1;
        }
    }
    fclose(fptr_self);
    if(self_check != 1)
    {
        printf("\tnot found ! (wrong self id)\n");
        fclose(fptr_reserve);
        return;
    }
    struct reserve reserve;
    Node_reserve *head_reserve = NULL;
    int self_id , self_end , self_start;
    while (fread(&reserve,sizeof(struct reserve),1,fptr_reserve))
    {
        add_node_reserve(&head_reserve,new_node_reserve(reserve));
        if(reserve.student_id == id_holder && date_comparition(reserve.tarikh_reserve , date_of_reserve) == 0 && strcmp(meal_type,reserve.meal) == 0)
        {
            self_id = reserve.self_id;
            reserve_check = 1;
        }
    }
    fclose(fptr_reserve);
    if(reserve_check != 1)
    {
        delete_all_reserve(head_reserve);
        printf("\tnot found ! (you haven't reserved in this date and meal)\n");
        return;
    }
    fptr_self = fopen("self.bin","rb");
    while(fread(&self,sizeof(struct self),1,fptr_self))
    {
        if(self.id == self_id)
        {
            if(strcmp(meal_type,"lunch") == 0)
            {
                self_start = self.lunch.start;
                self_end = self.lunch.end;
            }
            if(strcmp(meal_type,"dinner") == 0)
            {
                self_start = self.dinner.start;
                self_end = self.dinner.end;
            }
        }
    }
    fclose(fptr_self);
    if((is_more_than_3_hours(time_now , self_start) == 0 && date_comparition(today,reserve.tarikh_reserve) == 0)|| date_comparition(today,reserve.tarikh_reserve) < -1)
    {
        delete_all_reserve(head_reserve);
        printf("\tyou can't change the self, now!\n");
        return;
    }
    change_self_id(head_reserve,id_holder,new_self_id,date_of_reserve,meal_type);
    write_file_self_id_change(head_reserve);
    delete_all_reserve(head_reserve);
    printf("\tself successfully changed !\n");
    return;
}

void change_self_id(Node_reserve *head , int id_holder , int new_self_id , struct date reservation_date , char meal[])
{
    Node_reserve *current = head;
    while (current != NULL)
    {
        if(current->reserve.student_id == id_holder && date_comparition(current->reserve.tarikh_reserve , reservation_date) == 0 && strcmp(meal , current->reserve.meal) == 0)
        {
            current->reserve.self_id = new_self_id;
        }
        current = current->next;
    }
    
}

void write_file_self_id_change(Node_reserve *head_reserve)
{
    Node_reserve *current = head_reserve;
    struct reserve reserve;
    FILE *fptr_reserve = fopen("reserve.bin","wb");
    while (current != NULL)
    {
        fwrite(&reserve,sizeof(struct reserve),1,fptr_reserve);
        current = current->next;
    }
    fclose(fptr_reserve);
    return;
}

int is_more_than_3_hours(int time_now , int end_time)
{
    int time_now_hour = (time_now)-(time_now % 100) , time_now_min = time_now % 100 , end_time_hour = (end_time)-(end_time % 100) , end_time_min = end_time % 100;
    if((end_time_hour*60 + end_time_min)-(time_now_hour*60 + time_now_min) >= 180)
        return 1;
    else  
        return 0;
}

void financial_report(int id_holder)
{
    FILE *fptr = fopen("financial.bin","rb");
    struct financial financial;
    printf("these are your financial activities :\n");
    while (fread(&financial,sizeof(struct financial),1,fptr))
    {
        if(financial.student_id == id_holder)
        {
            printf("\tamount of money : %d\n",financial.money);
            printf("\tcause of action : %s\n\n",financial.operation);
        }
    }
    fclose(fptr);
    return;
}

void write_file_financial(int student_id , int amount , char oprt[], struct date today)
{
    struct financial financial;
    financial.student_id = student_id;
    financial.money = amount;
    financial.date = today;
    strcpy(financial.operation , oprt);
    FILE *fptr = fopen("financial.bin","ab");
    fwrite(&financial,sizeof(struct financial),1,fptr);
    fclose(fptr);
    return;
}

void write_file_food_delivery(int student_id,int self_id,char meal_type[],struct date Date,int current_time_minute,int current_time_hour,int food_id)
{
    struct food_delivery delivery;
    delivery.student_id = student_id;
    delivery.self_id = self_id;
    strcpy(delivery.meal_type,meal_type);
    delivery.date = Date;
    delivery.minute = current_time_minute;
    delivery.hour = current_time_hour;
    delivery.food_id = food_id;
    FILE *fptr = fopen("fooddelivery.bin","ab");
    fwrite(&delivery,sizeof(struct food_delivery),1,fptr);
    fclose(fptr);
    return;
}

void food_delivery_report(int id_holder)
{
    struct food_delivery delivery;
    FILE *fptr = fopen("fooddelivery.bin","rb");
    printf("\tthis is your food delivery report :\n");
    while (fread(&delivery,sizeof(struct food_delivery),1,fptr))
    {
        if(delivery.student_id == id_holder)
        {
            printf("\tself id : %d\n",delivery.self_id);
            printf("\tmeal : %s\n",delivery.meal_type);
            printf("\tfood id : %d\n",delivery.food_id);
            printf("\ttime : %d : %d\n",delivery.hour,delivery.minute);
            printf("\tdate : %d-%d-%d\n\n",delivery.date.year,delivery.date.month,delivery.date.day);
        }
    }
    fclose(fptr);
    return;
}

int reserved_food_count_in_self(int self_id , char meal[] , struct date date , int food_id)
{
    FILE *fptr = fopen("reserve.bin","rb");
    struct reserve reserve;
    int count = 0;
    while (fread(&reserve,sizeof(struct reserve),1,fptr))
    {
        if(reserve.self_id == self_id && strcmp(meal,reserve.meal) == 0 && date_comparition(date,reserve.tarikh_reserve) == 0 && food_id == reserve.food_id)
        {
            count++;
        }
    } 
    fclose(fptr);
    return count;
}

int count_total_food(struct date date , char meal[])
{
    FILE *fptr = fopen("reserve.bin","rb");
    struct reserve reserve;
    int count = 0;
    while(fread(&reserve,sizeof(struct reserve),1,fptr))
    {
        if(date_comparition(date,reserve.tarikh_reserve) == 0 && strcmp(meal,reserve.meal) == 0)
        {
            count++;
        }
    }
    fclose(fptr);
    return count;
}

int count_taken_food(int self_id , int food_id , struct date date)
{
    struct reserve reserve;
    int count = 0;
    FILE *fptr = fopen("takefood.bin","rb");
    while(fread(&reserve,sizeof(struct reserve),1,fptr))
    {
        if(reserve.self_id == self_id && reserve.food_id == food_id && date_comparition(date,reserve.tarikh_reserve) == 0)
        {
            count++;
        }
    }
    fclose(fptr);
    return count;
}

int count_total_taken_food(struct date date,char meal_type[])
{
    struct reserve reserve;
    FILE *fptr = fopen("takefood.bin","rb");
    int count = 0;
    while(fread(&reserve,sizeof(struct reserve),1,fptr))
    {
        if(strcmp(reserve.meal,meal_type) == 0 && date_comparition(date,reserve.tarikh_reserve) == 0)
        {
            count++;   
        }
    }
    fclose(fptr);
    return count;
}

void added_charge(int student_id,struct date start,struct date end)
{
    FILE *fptr = fopen("financial.bin","rb");
    struct financial financial;
    printf("\there is the list of actions leaded to change charge :\n");
    while (fread(&financial,sizeof(struct financial),1,fptr))
    {
        if(date_comparition(start,financial.date) >= 0 && date_comparition(end,financial.date) <= 0 && student_id == financial.student_id)
        {
            printf("\taction : %s    amount : %d    date : %d-%d-%d\n",financial.operation,financial.money,financial.date.year,financial.date.month,financial.date.day);
        }
    }
    printf("\n");
    fclose(fptr);
    return;
}

void canceled_reservation(int student_id,struct date start,struct date end)
{
    FILE *fptr = fopen("financial.bin","rb");
    struct financial financial;
    printf("\there is the list of dates of canceled reservation\n");
    while(fread(&financial,sizeof(struct financial),1,fptr))
    {
        if(date_comparition(start,financial.date) >= 0 && date_comparition(end,financial.date) <= 0 && student_id == financial.student_id && strcmp("canceling reservation",financial.operation) == 0)
        {
            printf("\t%d-%d-%d\n",financial.date.year,financial.date.month,financial.date.day);
        }
    }
    fclose(fptr);
    return;
}

void reserved_food(int student_id,struct date start,struct date end)
{
    FILE * fptr = fopen("financial.bin","rb") , *fptr1= fopen("reserve.bin","rb");
    struct financial financial;
    struct reserve reserve;
    printf("\there is the list of reservation:\n");
    while(fread(&financial,sizeof(struct financial),1,fptr))
    {
        if(date_comparition(start,financial.date) >= 0 && date_comparition(end,financial.date) <= 0 && student_id == financial.student_id && strcmp("reserving",financial.operation) == 0)
        {
            printf("\t%d-%d-%d\n",financial.date.year,financial.date.month,financial.date.day);
        }
        while(fread(&reserve,sizeof(struct reserve),1,fptr1))
        {
            if(date_comparition(financial.date,reserve.tarikh_reserve) == 0 && reserve.student_id == student_id)
            {
                printf("\tfood id : %d   self id : %d    meal : %s\n",reserve.food_id,reserve.self_id,reserve.meal);
            }
        }
    }
    fclose(fptr);
    fclose(fptr1);
    return;
}

void taken_food(int student_id,struct date start,struct date end)
{
    FILE *fptr = fopen("takefood.bin","rb");
    struct reserve reserve;
    printf("\there is the list of taken foods\n");
    while(fread(&reserve,sizeof(struct reserve),1,fptr))
    {
        if(date_comparition(start,reserve.tarikh_reserve) >= 0 && date_comparition(end,reserve.tarikh_reserve) <= 0 && student_id == reserve.student_id)
        {
            printf("\tmeal : %s\n",reserve.meal);
            printf("\tdate : %d-%d-%d\n",reserve.tarikh_reserve.year,reserve.tarikh_reserve.month,reserve.tarikh_reserve.day);
            printf("\tself_id : %d     food id : %d\n",reserve.self_id,reserve.food_id);
        }
    }
    fclose(fptr);
    return;
}

int is_two_days_or_more(struct date today, struct date date)
{
    int sum1 = 0 , sum2 = 0;
    sum1 += (today.year - 1900)* 366;
    sum2 += (date.year - 1900) * 366;
    if(today.month > 6)
    {
        sum1 += today.month * 30;
    }
    if(today.month <= 6)
    {
        sum1 += today.month * 31;
    }
    if(date.month > 6)
    {
        sum2 += today.month * 30;
    }
    if(date.month <= 6)
    {
        sum2 += today.month * 31;
    }
    sum1 += today.day;
    sum2 += date.day;
    if(sum2 - sum1 >= 2 && sum2 - sum1 <= 14)
        return 1;
    else
        return 0;
}

int check_validation_of_selfid(int self_id , struct date date)
{
    int check = 0;
    FILE *fptr = fopen("mealplan.bin","rb");
    struct meal_plan meal_plan;
    while (fread(&meal_plan,sizeof(struct meal_plan),1,fptr))
    {
        if(meal_plan.self_id == self_id && date_comparition(date,meal_plan.tarikh) == 0)
        {
            check = 1;
        }
    }
    fclose(fptr);
    return check;
}

int check_food_validation(int food_id , char meal_type[] , int self_id , struct date date)
{
    FILE *fptr = fopen("mealplan.bin","rb");
    int check = 0;
    struct meal_plan meal_plan;
    while(fread(&meal_plan,sizeof(struct meal_plan),1,fptr))
    {
        if(meal_plan.self_id == self_id && date_comparition(meal_plan.tarikh,date) == 0 && meal_plan.food_id == food_id && strcmp(meal_plan.type,meal_type) == 0)
        {
            check = 1;
        }
    }
    fclose(fptr);
    return check;
}

void return_the_food(int self_id,int food_id,struct date reservation)
{
    Node_meal_plan *head = NULL;
    struct meal_plan meal_plan;
    FILE *fptr = fopen("mealplan.bin","rb");
    while(fread(&meal_plan,sizeof(struct meal_plan),1,fptr))
    {
        add_node_meal_plan(&head,new_node_meal_plan(meal_plan));
    }
    fclose(fptr);
    Node_meal_plan *current = head;
    while (current != NULL)
    {
        if(current->MEALPLAN.food_id == food_id && current->MEALPLAN.self_id == self_id && date_comparition(reservation,current->MEALPLAN.tarikh) == 0)
        {
            current->MEALPLAN.count += 1;
        }
        current = current->next;
    }
    current = head;
    fptr = fopen("mealplan.bin","wb");
    while(current != NULL)
    {
        fwrite(&current->MEALPLAN,sizeof(struct meal_plan),1,fptr);
        current  = current->next;
    }
    fclose(fptr);
    return;
}

void set_time()
{
    display_time();
    int day,month,year,time1;
    printf("\tenter the date (2020-4-5) :\n");
    scanf("%d-%d-%d",&year,&month,&day);
    today.day = day;
    today.month = month;
    today.year = year;
    printf("\tenter the time you want to switch on (12:30 = 1230) :\n");
    scanf("%d",&time1);
    time_hour = (time1 - (time1 % 100))/100;
    time_min= time1 % 100;
    time_now = time1;
    printf("\ttime setted successfully\n");
    display_time();
}

void display_time()
{
    printf("\ttoday is : %d-%d-%d\n",today.year,today.month,today.day);
    printf("\ttime : %d:%d\n",time_hour,time_min);
}

int available_id_approve(Node *head_approve,int id_approve)
{
    Node *current = head_approve;
    while(current != NULL)
    {
        if(current->usr.id == id_approve)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
