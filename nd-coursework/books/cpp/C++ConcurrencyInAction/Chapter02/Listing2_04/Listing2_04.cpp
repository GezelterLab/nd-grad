// Copyright (c) 2019 by Anthony Williams. All rights reserved.
// Licensed under the Boost Software License. See the LICENSE file in the project root for more information.
//
// Name: Listing2_04.cpp
// Author: crdrisko
// Date: 12/26/2020-07:48:31
// Description: Detaching a thread to handle other documents

#include <string>
#include <thread>

void open_document_and_display_gui(std::string const& filename) {}
bool done_editing() { return true; }

enum command_type
{
    open_new_document
};

struct user_command
{
    command_type type;

    user_command() : type(open_new_document) {}
};

user_command get_user_input() { return user_command(); }
std::string get_filename_from_user() { return "foo.doc"; }
void process_user_input(user_command const&) {}

void edit_document(std::string const& filename)
{
    open_document_and_display_gui(filename);

    while (!done_editing())
    {
        user_command cmd = get_user_input();

        if (cmd.type == open_new_document)
        {
            std::string const new_name = get_filename_from_user();
            std::thread t(edit_document, new_name);
            t.detach();
        }
        else
        {
            process_user_input(cmd);
        }
    }
}

int main() { edit_document("bar.doc"); }
