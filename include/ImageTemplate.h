/* -------------------------------------------------------------------------- */
/* Copyright 2002-2010, OpenNebula Project Leads (OpenNebula.org)             */
/*                                                                            */
/* Licensed under the Apache License, Version 2.0 (the "License"); you may    */
/* not use this file except in compliance with the License. You may obtain    */
/* a copy of the License at                                                   */
/*                                                                            */
/* http://www.apache.org/licenses/LICENSE-2.0                                 */
/*                                                                            */
/* Unless required by applicable law or agreed to in writing, software        */
/* distributed under the License is distributed on an "AS IS" BASIS,          */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   */
/* See the License for the specific language governing permissions and        */
/* limitations under the License.                                             */
/* -------------------------------------------------------------------------- */

#ifndef IMAGE_TEMPLATE_H_
#define IMAGE_TEMPLATE_H_

#include "TemplateSQL.h"

using namespace std;

/**
 *  Image Template class, it represents the attributes of a Host
 */
class ImageTemplate : public TemplateSQL
{
public:
    ImageTemplate(int        tid       = -1,
                 const char separator = '='):
                 TemplateSQL(table,tid,true,separator,"TEMPLATE"){};

    ~ImageTemplate(){};

private:
    friend class Image;
    friend class ImagePool;
    
    static const char * table;
    
    static const char * db_bootstrap;
};
    
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

#endif /*IMAGE_TEMPLATE_H_*/