/******************************************************************
 *
 * Copyright 2015 Samsung Electronics All Rights Reserved.
 *
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************/

#ifndef INCLUDE_RESOLVER_H
#define INCLUDE_RESOLVER_H

#include "yaml-cpp/yaml.h"
#include "cJSON.h"
#include "Utils.h"
#include <fstream>
#include "yaml-cpp/exceptions.h"
#include "RamlExceptions.h"

namespace RAML
{
    class IncludeResolver
    {

        public:
            enum class FileType
            {
                NODE, JSON, FILE, NOTAG , ERROR
            };


        public:
            YAML::Node readToYamlNode(const YAML::Node &yamlFile );
            cJSON *readToJson(const YAML::Node &jsonFile );
            std::string readFromFile(const YAML::Node &file );
            FileType getFileType(const YAML::Node &yamlNode );
            cJSON *readToJson(const std::string &jsonFileName);

            IncludeResolver() {}
            IncludeResolver(const std::string &path) : m_path(path) {}
        private:
            std::string m_path;
    };
    typedef std::shared_ptr<IncludeResolver> IncludeResolverPtr;

}
#endif
