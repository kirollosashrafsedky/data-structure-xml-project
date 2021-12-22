#include "xmlToJson.h"

std::string xmlToJson(const XmlDocument& xml)
{
    if (xml.getRoot() == NULL)
    {
        return "error";
    }
    Json json;
    generateJsonTree(xml.getRoot(), json.getHeadNode());
    return json.toString();
}

void generateJsonTree(const XmlTreeNode* xmlNode, JsonNode* jsonNode)
{
    if (xmlNode->getNumberOfChildren() == 0)
    {
        if (xmlNode->getAttributes().size() == 0)
        {
            JsonFinalNode* finalChild = new JsonFinalNode(xmlNode->getTagName());
            finalChild->setNodeText(xmlNode->getValue());
            JsonNode* similarSibling = jsonNode;
            if (jsonNode->getNodeType() == JsonObjectNodeType)
            {
                if (static_cast<JsonCompoundNode*>(jsonNode)->searchChildren(finalChild->getNodeName(), &similarSibling))
                {
                    if (similarSibling->getNodeType() != JsonArrayNodeType)
                    {
                        JsonCompoundNode* parentArray = new JsonCompoundNode(JsonArrayNodeType, finalChild->getNodeName());
                        parentArray->appendChild(similarSibling);
                        parentArray->appendChild(finalChild);
                        static_cast<JsonCompoundNode*>(jsonNode)->deleteChild(similarSibling);
                        static_cast<JsonCompoundNode*>(jsonNode)->appendChild(parentArray);
                    }
                    else
                    {
                        static_cast<JsonCompoundNode*>(similarSibling)->appendChild(finalChild);
                    }
                }
                else
                {
                    static_cast<JsonCompoundNode*>(jsonNode)->appendChild(finalChild);
                }
            }
            else
            {
                static_cast<JsonCompoundNode*>(jsonNode)->appendChild(finalChild);
            }
        }
        else
        {
            JsonCompoundNode* finalChildObject = new JsonCompoundNode(JsonObjectNodeType, xmlNode->getTagName());
            JsonFinalNode* finalChildText = new JsonFinalNode("#text");
            finalChildText->setNodeText(xmlNode->getValue());
            finalChildObject->appendChild(finalChildText);
            for (int i = 0; i < xmlNode->getAttributes().size(); i++)
            {
                JsonFinalNode* finalChildAttr = new JsonFinalNode(xmlNode->getAttributes()[i]->getProperty());
                finalChildAttr->setNodeText(xmlNode->getAttributes()[i]->getValue());
                finalChildObject->appendChild(finalChildAttr);
            }
            JsonNode* similarSibling = jsonNode;
            if (jsonNode->getNodeType() == JsonObjectNodeType)
            {
                if (static_cast<JsonCompoundNode*>(jsonNode)->searchChildren(finalChildObject->getNodeName(), &similarSibling))
                {
                    if (similarSibling->getNodeType() != JsonArrayNodeType)
                    {
                        JsonCompoundNode* parentArray = new JsonCompoundNode(JsonArrayNodeType, finalChildObject->getNodeName());
                        parentArray->appendChild(similarSibling);
                        parentArray->appendChild(finalChildObject);
                        static_cast<JsonCompoundNode*>(jsonNode)->deleteChild(similarSibling);
                        static_cast<JsonCompoundNode*>(jsonNode)->appendChild(parentArray);
                    }
                    else
                    {
                        static_cast<JsonCompoundNode*>(similarSibling)->appendChild(finalChildObject);
                    }
                }
                else
                {
                    static_cast<JsonCompoundNode*>(jsonNode)->appendChild(finalChildObject);
                }
            }
            else
            {
                static_cast<JsonCompoundNode*>(jsonNode)->appendChild(finalChildObject);
            }
        }
    }
    else
    {
        JsonCompoundNode* childObject = new JsonCompoundNode(JsonObjectNodeType, xmlNode->getTagName());
        if (xmlNode->getValue() != "")
        {
            JsonFinalNode* finalChildText = new JsonFinalNode("#text");
            finalChildText->setNodeText(xmlNode->getValue());
            childObject->appendChild(finalChildText);
        }
        for (int i = 0; i < xmlNode->getAttributes().size(); i++)
        {
            JsonFinalNode* childAttr = new JsonFinalNode(xmlNode->getAttributes()[i]->getProperty());
            childAttr->setNodeText(xmlNode->getAttributes()[i]->getValue());
            childObject->appendChild(childAttr);
        }
        JsonNode* similarSibling = jsonNode;
        if (jsonNode->getNodeType() == JsonObjectNodeType)
        {
            if (static_cast<JsonCompoundNode*>(jsonNode)->searchChildren(childObject->getNodeName(), &similarSibling))
            {
                if (similarSibling->getNodeType() != JsonArrayNodeType)
                {
                    JsonCompoundNode* parentArray = new JsonCompoundNode(JsonArrayNodeType, childObject->getNodeName());
                    parentArray->appendChild(similarSibling);
                    parentArray->appendChild(childObject);
                    static_cast<JsonCompoundNode*>(jsonNode)->deleteChild(similarSibling);
                    static_cast<JsonCompoundNode*>(jsonNode)->appendChild(parentArray);
                }
                else
                {
                    static_cast<JsonCompoundNode*>(similarSibling)->appendChild(childObject);
                }
            }
            else
            {
                static_cast<JsonCompoundNode*>(jsonNode)->appendChild(childObject);
            }
        }
        else
        {
            static_cast<JsonCompoundNode*>(jsonNode)->appendChild(childObject);
        }
        for (int i = 0; i < xmlNode->getNumberOfChildren(); i++)
        {
            generateJsonTree(xmlNode->getChildren()[i], childObject);
        }
    }
}
