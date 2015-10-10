// Author: Jarrett Locke
// Class: Database Management
// Major: Computer Science - Game Development Consentration
//
// Assignment: 
//  Given a .txt file with information. Generate an .sql file with
//      commands that will drop the tables Student, Faculty, Class, and Enroll
//      if they exist and then create those tables. After the tables are
//      created, we are to populate each table with data given in the .txt file.
//
// Assumptions:
//  Since the information and the file is given, I can assume it to be static.
//      - if statements should not be required.
//      - very straightforward code.
//      - file is in same directory as executable.
//
//  Will approach this planning on working on the data in bulk.
//      - Get all lines in file first.
//      - Generate the SQL for Dropping the tables.
//          -Order:
//              -Enroll
//              -Class
//              -Faculty
//              -Student
//      - Generate the SQL for Creating the tables.
//          -Order:
//              -Student
//              -Faculty
//              -Class
//              -Enroll
//      - Work on each line.
//          - Grab table name or skip it?
//          - Grab all information into variables or just directly insert
//              data into query?
//          - Again, probably shouldn't need an if statement.
//      - Generate insert queries for inserting information into tables.
//      - Write lines to an .sql output file.
//
//  NOTE: I DO KNOW THAT THIS IS PRETTY MUCH JUST C CODE. I STILL USE CPP HEADERS
//      CUZ REASONS. >:(

#include <cstdio>
#include <cstring>

int
main()
{
    // Variables go here.
    FILE *i_file, *o_file;
    char tables[ 4 ][ 20 ];
    char classInfo[ 48 ][ 20 ];
    char enrollInfo[ 90 ][ 20 ];
    char facultyInfo[ 20 ][ 20 ];
    char studentInfo[ 90 ][ 20 ];
    // 30 + 12 + 18 + 5 + ( 4 to drop ) + ( 4 to insert ) = 73
    char queries[ 73 ][ 400 ];
    int track = 8;
    
    // Open information.txt file for reading.
    i_file = fopen( "information.txt", "r" );

    // Check if file is actually open. Abort if not open.
    if ( i_file == NULL )
    {
        printf( "Failed to open file." );
        return 1;
    }

    // All needed information is preceeded by the table name, 
    // get the name first. ( in this case, "CLass"
    fscanf( i_file, "%s", &tables[ 2 ] );
    
    // Get the information for the insert queries next.
    for ( int i = 0; i < 48; ++i )
    {
        fscanf( i_file, "%s", &classInfo[ i ] );
    }

    // Get  "Enroll" next.
    fscanf( i_file, "%s", &tables[ 3 ] );

    // Enroll information
    for ( int i = 0; i < 90; ++i )
    {
        fscanf( i_file, "%s", &enrollInfo[ i ] );
    }

    // "Faculty"
    fscanf( i_file, "%s", &tables[ 1 ] );

    // faculty information
    for ( int i = 0; i < 20; ++i )
    {
        fscanf( i_file, "%s", &facultyInfo[ i ] );
    }

    // "Student"
    fscanf( i_file, "%s", &tables[ 0 ] );

    // student information
    for ( int i = 0; i < 90; ++i )
    {
        fscanf( i_file, "%s", &studentInfo[ i ] );
    }

    // generate drop table statements.
    for( int i = 3; i >= 0; --i )
    {
        strcat( queries[ i ], "drop table if exists " );
        strcat( queries[ i ], tables[ i ] );
        strcat( queries[ i ], ";" );
    }

    // generate create statements for the tables.
    strcat( queries[ 4 ], "CREATE TABLE Student(stuId VARCHAR(6), lastName VARCHAR(20) NOT NULL, firstName VARCHAR(20) NOT NULL, major VARCHAR(10), credits int(3) DEFAULT 0, CONSTRAINT Student_stuId_pk PRIMARY KEY (stuId), CONSTRAINT Student_credits_cc CHECK ((credits>=0) AND (credits < 150)));" );
    strcat( queries[ 5 ], "CREATE TABLE Faculty(facId VARCHAR(6), name VARCHAR(20) NOT NULL, department VARCHAR(20), rank VARCHAR(10), CONSTRAINT Faculty_facId_pk PRIMARY KEY (facId));" );
    strcat( queries[ 6 ], "CREATE TABLE Class(classNumber VARCHAR(8), facId VARCHAR(6), schedule VARCHAR(8), room VARCHAR(6), CONSTRAINT Class_classNumber_pk PRIMARY KEY (classNumber), CONSTRAINT Class_facId_fk FOREIGN KEY (facId) REFERENCES Faculty (facId)  ON DELETE SET NULL, CONSTRAINT Class_schedule_room_uk UNIQUE (schedule, room));" );
    strcat( queries[ 7 ], "CREATE TABLE Enroll(stuId VARCHAR(6), classNumber VARCHAR(8), grade VARCHAR(2), CONSTRAINT Enroll_classNumber_stuId_pk PRIMARY KEY (classNumber, stuId), CONSTRAINT Enroll_classNumber_fk FOREIGN KEY (classNumber) REFERENCES Class (classNumber) ON DELETE CASCADE, CONSTRAINT Enroll_stuId_fk FOREIGN KEY (stuId) REFERENCES Student (stuId) ON DELETE CASCADE);" );

    // Insert statements for Student table
    for ( int i = 0; i < 90; i += 5 )
    {
        queries[ track ][ 0 ] = '\0';
        strcat( queries[ track ], "insert into " );
        strcat( queries[ track ], tables[ 0 ] );
        strcat( queries[ track ], " values (" );
        strcat( queries[ track ], studentInfo[ i ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], studentInfo[ i + 1 ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], studentInfo[ i + 2 ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], studentInfo[ i + 3 ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], studentInfo[ i + 4 ] );
        strcat( queries[ track ], ");" );
        ++track;
    }

    // Insert statements for Facutly table
    for ( int i = 0; i < 20; i += 4 )
    {
        queries[ track ][ 0 ] = '\0';
        strcat( queries[ track ], "insert into " );
        strcat( queries[ track ], tables[ 1 ] );
        strcat( queries[ track ], " values (" );
        strcat( queries[ track ], facultyInfo[ i ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], facultyInfo[ i + 1 ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], facultyInfo[ i + 2 ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], facultyInfo[ i + 3 ] );
        strcat( queries[ track ], ");" );
        ++track;
    }
    
    // Insert statements for Class table
    for ( int i = 0; i < 48; i += 4 )
    {
        queries[ track ][ 0 ] = '\0';
        strcat( queries[ track ], "insert into " );
        strcat( queries[ track ], tables[ 2 ] );
        strcat( queries[ track ], " values (" );
        strcat( queries[ track ], classInfo[ i ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], classInfo[ i + 1 ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], classInfo[ i + 2 ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], classInfo[ i + 3 ] );
        strcat( queries[ track ], ");" );
        ++track;
    }

    // Insert statements for Enroll table
    for ( int i = 0; i < 90; i += 3 )
    {
        queries[ track ][ 0 ] = '\0';
        strcat( queries[ track ], "insert into " );
        strcat( queries[ track ], tables[ 3 ] );
        strcat( queries[ track ], " values (" );
        strcat( queries[ track ], enrollInfo[ i ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], enrollInfo[ i + 1 ] );
        strcat( queries[ track ], ", " );
        strcat( queries[ track ], enrollInfo[ i + 2 ] );
        strcat( queries[ track ], ");" );
        ++track;
    }

    o_file = fopen( "sqloutput.sql", "w" );

    for ( int i = 0; i < 73; ++i )
    {
        fprintf( o_file, "%s\n", queries[ i ] );
    }

    return 0;
}
