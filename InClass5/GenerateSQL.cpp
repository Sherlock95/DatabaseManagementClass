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

#include <cstdio>

int
main()
{
    // Variables go here.
    FILE *i_file, *o_file;
    std::string tables[ 4 ];
    std::string facultyInfo[ 5 ];
    std::string studentInfo[ 18 ];
    std::string classInfo[ 12 ];
    std::string enrollInfo[ 30 ];
    // 30 + 12 + 18 + 5 + ( 4 to drop ) + ( 4 to insert ) = 73
    std::string queries[ 73 ];
    
    i_file = fopen( "information.txt", "r" );

    if ( i_file == NULL )
    {
        fprintf( STDERR, "Failed to open file." );
        exit( 1 );
    }

    fscanf( i_file, "%s", tables[ 0 ] );

    return 0;
}
