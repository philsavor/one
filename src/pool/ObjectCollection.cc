/* -------------------------------------------------------------------------- */
/* Copyright 2002-2011, OpenNebula Project Leads (OpenNebula.org)             */
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

#include "ObjectCollection.h"

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

int ObjectCollection::from_xml_node(const xmlNodePtr node)
{
    ObjectXML   xml(node);
    int         rc = 0;
    int         id;

    vector<string>              values;
    vector<string>::iterator    it;
    istringstream               iss;

    string xpath_expr = "/" + collection_name + "/ID";

    values = xml[xpath_expr.c_str()];

    for ( it = values.begin() ; it < values.end(); it++ )
    {
        iss.str(*it);
        iss >> dec >> id;

        if ( iss.fail() )
        {
            rc = -1;
        }
        else
        {
            collection_set.insert(id);
        }
    }

    return rc;
};

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

string& ObjectCollection::to_xml(string& xml) const
{
    ostringstream       oss;
    set<int>::iterator  it;

    oss << "<" << collection_name << ">";

    for ( it = collection_set.begin(); it != collection_set.end(); it++ )
    {
        oss << "<ID>" << *it << "</ID>";
    }

    oss << "</" << collection_name << ">";

    xml = oss.str();

    return xml;
};

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

int ObjectCollection::add_collection_id(int id)
{
    pair<set<int>::iterator,bool> ret;

    ret = collection_set.insert(id);

    if( !ret.second )
    {
        return -1;
    }

    return 0;
};

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

int ObjectCollection::del_collection_id(int id)
{
    if( collection_set.erase(id) != 1 )
    {
        return -1;
    }

    return 0;
};
