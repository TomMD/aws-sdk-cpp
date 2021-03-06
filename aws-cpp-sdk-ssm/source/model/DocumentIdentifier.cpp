﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/ssm/model/DocumentIdentifier.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace SSM
{
namespace Model
{

DocumentIdentifier::DocumentIdentifier() : 
    m_nameHasBeenSet(false),
    m_ownerHasBeenSet(false),
    m_platformTypesHasBeenSet(false),
    m_documentVersionHasBeenSet(false),
    m_documentType(DocumentType::NOT_SET),
    m_documentTypeHasBeenSet(false),
    m_schemaVersionHasBeenSet(false),
    m_documentFormat(DocumentFormat::NOT_SET),
    m_documentFormatHasBeenSet(false),
    m_targetTypeHasBeenSet(false),
    m_tagsHasBeenSet(false)
{
}

DocumentIdentifier::DocumentIdentifier(const JsonValue& jsonValue) : 
    m_nameHasBeenSet(false),
    m_ownerHasBeenSet(false),
    m_platformTypesHasBeenSet(false),
    m_documentVersionHasBeenSet(false),
    m_documentType(DocumentType::NOT_SET),
    m_documentTypeHasBeenSet(false),
    m_schemaVersionHasBeenSet(false),
    m_documentFormat(DocumentFormat::NOT_SET),
    m_documentFormatHasBeenSet(false),
    m_targetTypeHasBeenSet(false),
    m_tagsHasBeenSet(false)
{
  *this = jsonValue;
}

DocumentIdentifier& DocumentIdentifier::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("Name"))
  {
    m_name = jsonValue.GetString("Name");

    m_nameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Owner"))
  {
    m_owner = jsonValue.GetString("Owner");

    m_ownerHasBeenSet = true;
  }

  if(jsonValue.ValueExists("PlatformTypes"))
  {
    Array<JsonValue> platformTypesJsonList = jsonValue.GetArray("PlatformTypes");
    for(unsigned platformTypesIndex = 0; platformTypesIndex < platformTypesJsonList.GetLength(); ++platformTypesIndex)
    {
      m_platformTypes.push_back(PlatformTypeMapper::GetPlatformTypeForName(platformTypesJsonList[platformTypesIndex].AsString()));
    }
    m_platformTypesHasBeenSet = true;
  }

  if(jsonValue.ValueExists("DocumentVersion"))
  {
    m_documentVersion = jsonValue.GetString("DocumentVersion");

    m_documentVersionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("DocumentType"))
  {
    m_documentType = DocumentTypeMapper::GetDocumentTypeForName(jsonValue.GetString("DocumentType"));

    m_documentTypeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("SchemaVersion"))
  {
    m_schemaVersion = jsonValue.GetString("SchemaVersion");

    m_schemaVersionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("DocumentFormat"))
  {
    m_documentFormat = DocumentFormatMapper::GetDocumentFormatForName(jsonValue.GetString("DocumentFormat"));

    m_documentFormatHasBeenSet = true;
  }

  if(jsonValue.ValueExists("TargetType"))
  {
    m_targetType = jsonValue.GetString("TargetType");

    m_targetTypeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Tags"))
  {
    Array<JsonValue> tagsJsonList = jsonValue.GetArray("Tags");
    for(unsigned tagsIndex = 0; tagsIndex < tagsJsonList.GetLength(); ++tagsIndex)
    {
      m_tags.push_back(tagsJsonList[tagsIndex].AsObject());
    }
    m_tagsHasBeenSet = true;
  }

  return *this;
}

JsonValue DocumentIdentifier::Jsonize() const
{
  JsonValue payload;

  if(m_nameHasBeenSet)
  {
   payload.WithString("Name", m_name);

  }

  if(m_ownerHasBeenSet)
  {
   payload.WithString("Owner", m_owner);

  }

  if(m_platformTypesHasBeenSet)
  {
   Array<JsonValue> platformTypesJsonList(m_platformTypes.size());
   for(unsigned platformTypesIndex = 0; platformTypesIndex < platformTypesJsonList.GetLength(); ++platformTypesIndex)
   {
     platformTypesJsonList[platformTypesIndex].AsString(PlatformTypeMapper::GetNameForPlatformType(m_platformTypes[platformTypesIndex]));
   }
   payload.WithArray("PlatformTypes", std::move(platformTypesJsonList));

  }

  if(m_documentVersionHasBeenSet)
  {
   payload.WithString("DocumentVersion", m_documentVersion);

  }

  if(m_documentTypeHasBeenSet)
  {
   payload.WithString("DocumentType", DocumentTypeMapper::GetNameForDocumentType(m_documentType));
  }

  if(m_schemaVersionHasBeenSet)
  {
   payload.WithString("SchemaVersion", m_schemaVersion);

  }

  if(m_documentFormatHasBeenSet)
  {
   payload.WithString("DocumentFormat", DocumentFormatMapper::GetNameForDocumentFormat(m_documentFormat));
  }

  if(m_targetTypeHasBeenSet)
  {
   payload.WithString("TargetType", m_targetType);

  }

  if(m_tagsHasBeenSet)
  {
   Array<JsonValue> tagsJsonList(m_tags.size());
   for(unsigned tagsIndex = 0; tagsIndex < tagsJsonList.GetLength(); ++tagsIndex)
   {
     tagsJsonList[tagsIndex].AsObject(m_tags[tagsIndex].Jsonize());
   }
   payload.WithArray("Tags", std::move(tagsJsonList));

  }

  return payload;
}

} // namespace Model
} // namespace SSM
} // namespace Aws
