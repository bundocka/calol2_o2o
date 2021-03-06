#ifndef __l1t_XmlConfigReader_h__
#define __l1t_XmlConfigReader_h__

#include <string>
#include <vector>

#include "xercesc/util/XercesDefs.hpp"
#include "xercesc/parsers/XercesDOMParser.hpp"
#include "xercesc/dom/DOM.hpp"
#include "xercesc/framework/MemBufInputSource.hpp"

namespace XERCES_CPP_NAMESPACE {

class DOMNode;
class XercesDOMParser;

}

namespace l1t {

class trigSystem;

class XmlConfigReader {

 public:

  const XMLCh* kTagHw;
  const XMLCh* kTagAlgo;
  const XMLCh* kTagRunSettings;
  const XMLCh* kTagDb;
  const XMLCh* kTagKey;
  const XMLCh* kTagLoad;
  const XMLCh* kTagContext;
  const XMLCh* kTagParam;
  const XMLCh* kTagMask;
  const XMLCh* kTagDisable;
  const XMLCh* kTagColumns;
  const XMLCh* kTagTypes;
  const XMLCh* kTagRow;
  const XMLCh* kTagProcessor;
  const XMLCh* kTagRole;
  const XMLCh* kTagCrate;
  const XMLCh* kAttrId;
  const XMLCh* kAttrType;
  const XMLCh* kAttrDelim;
  const XMLCh* kAttrModule;
  const std::string kTypeTable;

  XmlConfigReader();
  XmlConfigReader(xercesc::DOMDocument* doc);
  ~XmlConfigReader();
  void readDOMFromString(const std::string& str, xercesc::DOMDocument*& doc);
  void readDOMFromString(const std::string& str);
  void readDOMFromFile(const std::string& fName, xercesc::DOMDocument*& doc);
  void readDOMFromFile(const std::string& fName);
  void readRootElement(trigSystem& aTrigSystem, const std::string& sysId = "");
  void readElement(const xercesc::DOMElement* element, trigSystem& aTrigSystem, const std::string& sysId = "");
  void readHwDescription(const xercesc::DOMElement* element, trigSystem& aTrigSystem, const std::string& sysId = "");
  void readContext(const xercesc::DOMElement* element, const std::string& sysId, trigSystem& aTrigSystem);
  void readContexts(const std::string& key, const std::string& sysId, trigSystem& aTrigSystem);
  xercesc::DOMElement* getKeyElement(const std::string& key);
  void buildGlobalDoc(const std::string& key, const std::string& topPath = "");

 private:

  xercesc::XercesDOMParser* parser_;
  xercesc::DOMDocument* doc_;

  void appendNodesFromSubDoc(xercesc::DOMNode* parentNode, xercesc::DOMDocument* subDoc);
  void pruneString(std::string& str);
  char* pruneString(char* &str);
};

}
#endif
