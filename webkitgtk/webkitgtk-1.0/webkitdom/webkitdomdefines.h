/* This file is part of the WebKit open source project.
   This file has been generated by gobject-generate-headers.pl.  DO NOT MODIFY!
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef webkitdomdefines_h
#define webkitdomdefines_h

#include <glib.h>

#ifdef G_OS_WIN32
    #ifdef BUILDING_WEBKIT
        #define WEBKIT_API __declspec(dllexport)
    #else
        #define WEBKIT_API __declspec(dllimport)
    #endif
#else
    #define WEBKIT_API __attribute__((visibility("default")))
#endif

#define WEBKIT_DEPRECATED WEBKIT_API G_DEPRECATED
#define WEBKIT_DEPRECATED_FOR(f) WEBKIT_API G_DEPRECATED_FOR(f)

#ifndef WEBKIT_API
    #define WEBKIT_API
#endif
typedef struct _WebKitDOMAttr WebKitDOMAttr;
typedef struct _WebKitDOMAttrClass WebKitDOMAttrClass;

typedef struct _WebKitDOMAudioTrack WebKitDOMAudioTrack;
typedef struct _WebKitDOMAudioTrackClass WebKitDOMAudioTrackClass;

typedef struct _WebKitDOMAudioTrackList WebKitDOMAudioTrackList;
typedef struct _WebKitDOMAudioTrackListClass WebKitDOMAudioTrackListClass;

typedef struct _WebKitDOMBarProp WebKitDOMBarProp;
typedef struct _WebKitDOMBarPropClass WebKitDOMBarPropClass;

typedef struct _WebKitDOMBatteryManager WebKitDOMBatteryManager;
typedef struct _WebKitDOMBatteryManagerClass WebKitDOMBatteryManagerClass;

typedef struct _WebKitDOMBlob WebKitDOMBlob;
typedef struct _WebKitDOMBlobClass WebKitDOMBlobClass;

typedef struct _WebKitDOMCDATASection WebKitDOMCDATASection;
typedef struct _WebKitDOMCDATASectionClass WebKitDOMCDATASectionClass;

typedef struct _WebKitDOMCSSRule WebKitDOMCSSRule;
typedef struct _WebKitDOMCSSRuleClass WebKitDOMCSSRuleClass;

typedef struct _WebKitDOMCSSRuleList WebKitDOMCSSRuleList;
typedef struct _WebKitDOMCSSRuleListClass WebKitDOMCSSRuleListClass;

typedef struct _WebKitDOMCSSStyleDeclaration WebKitDOMCSSStyleDeclaration;
typedef struct _WebKitDOMCSSStyleDeclarationClass WebKitDOMCSSStyleDeclarationClass;

typedef struct _WebKitDOMCSSStyleSheet WebKitDOMCSSStyleSheet;
typedef struct _WebKitDOMCSSStyleSheetClass WebKitDOMCSSStyleSheetClass;

typedef struct _WebKitDOMCSSValue WebKitDOMCSSValue;
typedef struct _WebKitDOMCSSValueClass WebKitDOMCSSValueClass;

typedef struct _WebKitDOMCharacterData WebKitDOMCharacterData;
typedef struct _WebKitDOMCharacterDataClass WebKitDOMCharacterDataClass;

typedef struct _WebKitDOMComment WebKitDOMComment;
typedef struct _WebKitDOMCommentClass WebKitDOMCommentClass;

typedef struct _WebKitDOMConsole WebKitDOMConsole;
typedef struct _WebKitDOMConsoleClass WebKitDOMConsoleClass;

typedef struct _WebKitDOMDOMApplicationCache WebKitDOMDOMApplicationCache;
typedef struct _WebKitDOMDOMApplicationCacheClass WebKitDOMDOMApplicationCacheClass;

typedef struct _WebKitDOMDOMImplementation WebKitDOMDOMImplementation;
typedef struct _WebKitDOMDOMImplementationClass WebKitDOMDOMImplementationClass;

typedef struct _WebKitDOMDOMMimeType WebKitDOMDOMMimeType;
typedef struct _WebKitDOMDOMMimeTypeClass WebKitDOMDOMMimeTypeClass;

typedef struct _WebKitDOMDOMMimeTypeArray WebKitDOMDOMMimeTypeArray;
typedef struct _WebKitDOMDOMMimeTypeArrayClass WebKitDOMDOMMimeTypeArrayClass;

typedef struct _WebKitDOMDOMNamedFlowCollection WebKitDOMDOMNamedFlowCollection;
typedef struct _WebKitDOMDOMNamedFlowCollectionClass WebKitDOMDOMNamedFlowCollectionClass;

typedef struct _WebKitDOMDOMPlugin WebKitDOMDOMPlugin;
typedef struct _WebKitDOMDOMPluginClass WebKitDOMDOMPluginClass;

typedef struct _WebKitDOMDOMPluginArray WebKitDOMDOMPluginArray;
typedef struct _WebKitDOMDOMPluginArrayClass WebKitDOMDOMPluginArrayClass;

typedef struct _WebKitDOMDOMSecurityPolicy WebKitDOMDOMSecurityPolicy;
typedef struct _WebKitDOMDOMSecurityPolicyClass WebKitDOMDOMSecurityPolicyClass;

typedef struct _WebKitDOMDOMSelection WebKitDOMDOMSelection;
typedef struct _WebKitDOMDOMSelectionClass WebKitDOMDOMSelectionClass;

typedef struct _WebKitDOMDOMSettableTokenList WebKitDOMDOMSettableTokenList;
typedef struct _WebKitDOMDOMSettableTokenListClass WebKitDOMDOMSettableTokenListClass;

typedef struct _WebKitDOMDOMStringList WebKitDOMDOMStringList;
typedef struct _WebKitDOMDOMStringListClass WebKitDOMDOMStringListClass;

typedef struct _WebKitDOMDOMStringMap WebKitDOMDOMStringMap;
typedef struct _WebKitDOMDOMStringMapClass WebKitDOMDOMStringMapClass;

typedef struct _WebKitDOMDOMTokenList WebKitDOMDOMTokenList;
typedef struct _WebKitDOMDOMTokenListClass WebKitDOMDOMTokenListClass;

typedef struct _WebKitDOMDOMWindow WebKitDOMDOMWindow;
typedef struct _WebKitDOMDOMWindowClass WebKitDOMDOMWindowClass;

typedef struct _WebKitDOMDOMWindowCSS WebKitDOMDOMWindowCSS;
typedef struct _WebKitDOMDOMWindowCSSClass WebKitDOMDOMWindowCSSClass;

typedef struct _WebKitDOMDatabase WebKitDOMDatabase;
typedef struct _WebKitDOMDatabaseClass WebKitDOMDatabaseClass;

typedef struct _WebKitDOMDocument WebKitDOMDocument;
typedef struct _WebKitDOMDocumentClass WebKitDOMDocumentClass;

typedef struct _WebKitDOMDocumentFragment WebKitDOMDocumentFragment;
typedef struct _WebKitDOMDocumentFragmentClass WebKitDOMDocumentFragmentClass;

typedef struct _WebKitDOMDocumentType WebKitDOMDocumentType;
typedef struct _WebKitDOMDocumentTypeClass WebKitDOMDocumentTypeClass;

typedef struct _WebKitDOMElement WebKitDOMElement;
typedef struct _WebKitDOMElementClass WebKitDOMElementClass;

typedef struct _WebKitDOMEntityReference WebKitDOMEntityReference;
typedef struct _WebKitDOMEntityReferenceClass WebKitDOMEntityReferenceClass;

typedef struct _WebKitDOMEvent WebKitDOMEvent;
typedef struct _WebKitDOMEventClass WebKitDOMEventClass;

typedef struct _WebKitDOMEventTarget WebKitDOMEventTarget;
typedef struct _WebKitDOMEventTargetClass WebKitDOMEventTargetClass;

typedef struct _WebKitDOMFile WebKitDOMFile;
typedef struct _WebKitDOMFileClass WebKitDOMFileClass;

typedef struct _WebKitDOMFileList WebKitDOMFileList;
typedef struct _WebKitDOMFileListClass WebKitDOMFileListClass;

typedef struct _WebKitDOMGamepad WebKitDOMGamepad;
typedef struct _WebKitDOMGamepadClass WebKitDOMGamepadClass;

typedef struct _WebKitDOMGamepadList WebKitDOMGamepadList;
typedef struct _WebKitDOMGamepadListClass WebKitDOMGamepadListClass;

typedef struct _WebKitDOMGeolocation WebKitDOMGeolocation;
typedef struct _WebKitDOMGeolocationClass WebKitDOMGeolocationClass;

typedef struct _WebKitDOMHTMLAnchorElement WebKitDOMHTMLAnchorElement;
typedef struct _WebKitDOMHTMLAnchorElementClass WebKitDOMHTMLAnchorElementClass;

typedef struct _WebKitDOMHTMLAppletElement WebKitDOMHTMLAppletElement;
typedef struct _WebKitDOMHTMLAppletElementClass WebKitDOMHTMLAppletElementClass;

typedef struct _WebKitDOMHTMLAreaElement WebKitDOMHTMLAreaElement;
typedef struct _WebKitDOMHTMLAreaElementClass WebKitDOMHTMLAreaElementClass;

typedef struct _WebKitDOMHTMLAudioElement WebKitDOMHTMLAudioElement;
typedef struct _WebKitDOMHTMLAudioElementClass WebKitDOMHTMLAudioElementClass;

typedef struct _WebKitDOMHTMLBRElement WebKitDOMHTMLBRElement;
typedef struct _WebKitDOMHTMLBRElementClass WebKitDOMHTMLBRElementClass;

typedef struct _WebKitDOMHTMLBaseElement WebKitDOMHTMLBaseElement;
typedef struct _WebKitDOMHTMLBaseElementClass WebKitDOMHTMLBaseElementClass;

typedef struct _WebKitDOMHTMLBaseFontElement WebKitDOMHTMLBaseFontElement;
typedef struct _WebKitDOMHTMLBaseFontElementClass WebKitDOMHTMLBaseFontElementClass;

typedef struct _WebKitDOMHTMLBodyElement WebKitDOMHTMLBodyElement;
typedef struct _WebKitDOMHTMLBodyElementClass WebKitDOMHTMLBodyElementClass;

typedef struct _WebKitDOMHTMLButtonElement WebKitDOMHTMLButtonElement;
typedef struct _WebKitDOMHTMLButtonElementClass WebKitDOMHTMLButtonElementClass;

typedef struct _WebKitDOMHTMLCanvasElement WebKitDOMHTMLCanvasElement;
typedef struct _WebKitDOMHTMLCanvasElementClass WebKitDOMHTMLCanvasElementClass;

typedef struct _WebKitDOMHTMLCollection WebKitDOMHTMLCollection;
typedef struct _WebKitDOMHTMLCollectionClass WebKitDOMHTMLCollectionClass;

typedef struct _WebKitDOMHTMLDListElement WebKitDOMHTMLDListElement;
typedef struct _WebKitDOMHTMLDListElementClass WebKitDOMHTMLDListElementClass;

typedef struct _WebKitDOMHTMLDetailsElement WebKitDOMHTMLDetailsElement;
typedef struct _WebKitDOMHTMLDetailsElementClass WebKitDOMHTMLDetailsElementClass;

typedef struct _WebKitDOMHTMLDirectoryElement WebKitDOMHTMLDirectoryElement;
typedef struct _WebKitDOMHTMLDirectoryElementClass WebKitDOMHTMLDirectoryElementClass;

typedef struct _WebKitDOMHTMLDivElement WebKitDOMHTMLDivElement;
typedef struct _WebKitDOMHTMLDivElementClass WebKitDOMHTMLDivElementClass;

typedef struct _WebKitDOMHTMLDocument WebKitDOMHTMLDocument;
typedef struct _WebKitDOMHTMLDocumentClass WebKitDOMHTMLDocumentClass;

typedef struct _WebKitDOMHTMLElement WebKitDOMHTMLElement;
typedef struct _WebKitDOMHTMLElementClass WebKitDOMHTMLElementClass;

typedef struct _WebKitDOMHTMLEmbedElement WebKitDOMHTMLEmbedElement;
typedef struct _WebKitDOMHTMLEmbedElementClass WebKitDOMHTMLEmbedElementClass;

typedef struct _WebKitDOMHTMLFieldSetElement WebKitDOMHTMLFieldSetElement;
typedef struct _WebKitDOMHTMLFieldSetElementClass WebKitDOMHTMLFieldSetElementClass;

typedef struct _WebKitDOMHTMLFontElement WebKitDOMHTMLFontElement;
typedef struct _WebKitDOMHTMLFontElementClass WebKitDOMHTMLFontElementClass;

typedef struct _WebKitDOMHTMLFormElement WebKitDOMHTMLFormElement;
typedef struct _WebKitDOMHTMLFormElementClass WebKitDOMHTMLFormElementClass;

typedef struct _WebKitDOMHTMLFrameElement WebKitDOMHTMLFrameElement;
typedef struct _WebKitDOMHTMLFrameElementClass WebKitDOMHTMLFrameElementClass;

typedef struct _WebKitDOMHTMLFrameSetElement WebKitDOMHTMLFrameSetElement;
typedef struct _WebKitDOMHTMLFrameSetElementClass WebKitDOMHTMLFrameSetElementClass;

typedef struct _WebKitDOMHTMLHRElement WebKitDOMHTMLHRElement;
typedef struct _WebKitDOMHTMLHRElementClass WebKitDOMHTMLHRElementClass;

typedef struct _WebKitDOMHTMLHeadElement WebKitDOMHTMLHeadElement;
typedef struct _WebKitDOMHTMLHeadElementClass WebKitDOMHTMLHeadElementClass;

typedef struct _WebKitDOMHTMLHeadingElement WebKitDOMHTMLHeadingElement;
typedef struct _WebKitDOMHTMLHeadingElementClass WebKitDOMHTMLHeadingElementClass;

typedef struct _WebKitDOMHTMLHtmlElement WebKitDOMHTMLHtmlElement;
typedef struct _WebKitDOMHTMLHtmlElementClass WebKitDOMHTMLHtmlElementClass;

typedef struct _WebKitDOMHTMLIFrameElement WebKitDOMHTMLIFrameElement;
typedef struct _WebKitDOMHTMLIFrameElementClass WebKitDOMHTMLIFrameElementClass;

typedef struct _WebKitDOMHTMLImageElement WebKitDOMHTMLImageElement;
typedef struct _WebKitDOMHTMLImageElementClass WebKitDOMHTMLImageElementClass;

typedef struct _WebKitDOMHTMLInputElement WebKitDOMHTMLInputElement;
typedef struct _WebKitDOMHTMLInputElementClass WebKitDOMHTMLInputElementClass;

typedef struct _WebKitDOMHTMLKeygenElement WebKitDOMHTMLKeygenElement;
typedef struct _WebKitDOMHTMLKeygenElementClass WebKitDOMHTMLKeygenElementClass;

typedef struct _WebKitDOMHTMLLIElement WebKitDOMHTMLLIElement;
typedef struct _WebKitDOMHTMLLIElementClass WebKitDOMHTMLLIElementClass;

typedef struct _WebKitDOMHTMLLabelElement WebKitDOMHTMLLabelElement;
typedef struct _WebKitDOMHTMLLabelElementClass WebKitDOMHTMLLabelElementClass;

typedef struct _WebKitDOMHTMLLegendElement WebKitDOMHTMLLegendElement;
typedef struct _WebKitDOMHTMLLegendElementClass WebKitDOMHTMLLegendElementClass;

typedef struct _WebKitDOMHTMLLinkElement WebKitDOMHTMLLinkElement;
typedef struct _WebKitDOMHTMLLinkElementClass WebKitDOMHTMLLinkElementClass;

typedef struct _WebKitDOMHTMLMapElement WebKitDOMHTMLMapElement;
typedef struct _WebKitDOMHTMLMapElementClass WebKitDOMHTMLMapElementClass;

typedef struct _WebKitDOMHTMLMarqueeElement WebKitDOMHTMLMarqueeElement;
typedef struct _WebKitDOMHTMLMarqueeElementClass WebKitDOMHTMLMarqueeElementClass;

typedef struct _WebKitDOMHTMLMediaElement WebKitDOMHTMLMediaElement;
typedef struct _WebKitDOMHTMLMediaElementClass WebKitDOMHTMLMediaElementClass;

typedef struct _WebKitDOMHTMLMenuElement WebKitDOMHTMLMenuElement;
typedef struct _WebKitDOMHTMLMenuElementClass WebKitDOMHTMLMenuElementClass;

typedef struct _WebKitDOMHTMLMetaElement WebKitDOMHTMLMetaElement;
typedef struct _WebKitDOMHTMLMetaElementClass WebKitDOMHTMLMetaElementClass;

typedef struct _WebKitDOMHTMLModElement WebKitDOMHTMLModElement;
typedef struct _WebKitDOMHTMLModElementClass WebKitDOMHTMLModElementClass;

typedef struct _WebKitDOMHTMLOListElement WebKitDOMHTMLOListElement;
typedef struct _WebKitDOMHTMLOListElementClass WebKitDOMHTMLOListElementClass;

typedef struct _WebKitDOMHTMLObjectElement WebKitDOMHTMLObjectElement;
typedef struct _WebKitDOMHTMLObjectElementClass WebKitDOMHTMLObjectElementClass;

typedef struct _WebKitDOMHTMLOptGroupElement WebKitDOMHTMLOptGroupElement;
typedef struct _WebKitDOMHTMLOptGroupElementClass WebKitDOMHTMLOptGroupElementClass;

typedef struct _WebKitDOMHTMLOptionElement WebKitDOMHTMLOptionElement;
typedef struct _WebKitDOMHTMLOptionElementClass WebKitDOMHTMLOptionElementClass;

typedef struct _WebKitDOMHTMLOptionsCollection WebKitDOMHTMLOptionsCollection;
typedef struct _WebKitDOMHTMLOptionsCollectionClass WebKitDOMHTMLOptionsCollectionClass;

typedef struct _WebKitDOMHTMLParagraphElement WebKitDOMHTMLParagraphElement;
typedef struct _WebKitDOMHTMLParagraphElementClass WebKitDOMHTMLParagraphElementClass;

typedef struct _WebKitDOMHTMLParamElement WebKitDOMHTMLParamElement;
typedef struct _WebKitDOMHTMLParamElementClass WebKitDOMHTMLParamElementClass;

typedef struct _WebKitDOMHTMLPreElement WebKitDOMHTMLPreElement;
typedef struct _WebKitDOMHTMLPreElementClass WebKitDOMHTMLPreElementClass;

typedef struct _WebKitDOMHTMLQuoteElement WebKitDOMHTMLQuoteElement;
typedef struct _WebKitDOMHTMLQuoteElementClass WebKitDOMHTMLQuoteElementClass;

typedef struct _WebKitDOMHTMLScriptElement WebKitDOMHTMLScriptElement;
typedef struct _WebKitDOMHTMLScriptElementClass WebKitDOMHTMLScriptElementClass;

typedef struct _WebKitDOMHTMLSelectElement WebKitDOMHTMLSelectElement;
typedef struct _WebKitDOMHTMLSelectElementClass WebKitDOMHTMLSelectElementClass;

typedef struct _WebKitDOMHTMLStyleElement WebKitDOMHTMLStyleElement;
typedef struct _WebKitDOMHTMLStyleElementClass WebKitDOMHTMLStyleElementClass;

typedef struct _WebKitDOMHTMLTableCaptionElement WebKitDOMHTMLTableCaptionElement;
typedef struct _WebKitDOMHTMLTableCaptionElementClass WebKitDOMHTMLTableCaptionElementClass;

typedef struct _WebKitDOMHTMLTableCellElement WebKitDOMHTMLTableCellElement;
typedef struct _WebKitDOMHTMLTableCellElementClass WebKitDOMHTMLTableCellElementClass;

typedef struct _WebKitDOMHTMLTableColElement WebKitDOMHTMLTableColElement;
typedef struct _WebKitDOMHTMLTableColElementClass WebKitDOMHTMLTableColElementClass;

typedef struct _WebKitDOMHTMLTableElement WebKitDOMHTMLTableElement;
typedef struct _WebKitDOMHTMLTableElementClass WebKitDOMHTMLTableElementClass;

typedef struct _WebKitDOMHTMLTableRowElement WebKitDOMHTMLTableRowElement;
typedef struct _WebKitDOMHTMLTableRowElementClass WebKitDOMHTMLTableRowElementClass;

typedef struct _WebKitDOMHTMLTableSectionElement WebKitDOMHTMLTableSectionElement;
typedef struct _WebKitDOMHTMLTableSectionElementClass WebKitDOMHTMLTableSectionElementClass;

typedef struct _WebKitDOMHTMLTextAreaElement WebKitDOMHTMLTextAreaElement;
typedef struct _WebKitDOMHTMLTextAreaElementClass WebKitDOMHTMLTextAreaElementClass;

typedef struct _WebKitDOMHTMLTitleElement WebKitDOMHTMLTitleElement;
typedef struct _WebKitDOMHTMLTitleElementClass WebKitDOMHTMLTitleElementClass;

typedef struct _WebKitDOMHTMLUListElement WebKitDOMHTMLUListElement;
typedef struct _WebKitDOMHTMLUListElementClass WebKitDOMHTMLUListElementClass;

typedef struct _WebKitDOMHTMLVideoElement WebKitDOMHTMLVideoElement;
typedef struct _WebKitDOMHTMLVideoElementClass WebKitDOMHTMLVideoElementClass;

typedef struct _WebKitDOMHistory WebKitDOMHistory;
typedef struct _WebKitDOMHistoryClass WebKitDOMHistoryClass;

typedef struct _WebKitDOMKeyboardEvent WebKitDOMKeyboardEvent;
typedef struct _WebKitDOMKeyboardEventClass WebKitDOMKeyboardEventClass;

typedef struct _WebKitDOMLocation WebKitDOMLocation;
typedef struct _WebKitDOMLocationClass WebKitDOMLocationClass;

typedef struct _WebKitDOMMediaController WebKitDOMMediaController;
typedef struct _WebKitDOMMediaControllerClass WebKitDOMMediaControllerClass;

typedef struct _WebKitDOMMediaError WebKitDOMMediaError;
typedef struct _WebKitDOMMediaErrorClass WebKitDOMMediaErrorClass;

typedef struct _WebKitDOMMediaList WebKitDOMMediaList;
typedef struct _WebKitDOMMediaListClass WebKitDOMMediaListClass;

typedef struct _WebKitDOMMediaQueryList WebKitDOMMediaQueryList;
typedef struct _WebKitDOMMediaQueryListClass WebKitDOMMediaQueryListClass;

typedef struct _WebKitDOMMessagePort WebKitDOMMessagePort;
typedef struct _WebKitDOMMessagePortClass WebKitDOMMessagePortClass;

typedef struct _WebKitDOMMouseEvent WebKitDOMMouseEvent;
typedef struct _WebKitDOMMouseEventClass WebKitDOMMouseEventClass;

typedef struct _WebKitDOMNamedNodeMap WebKitDOMNamedNodeMap;
typedef struct _WebKitDOMNamedNodeMapClass WebKitDOMNamedNodeMapClass;

typedef struct _WebKitDOMNavigator WebKitDOMNavigator;
typedef struct _WebKitDOMNavigatorClass WebKitDOMNavigatorClass;

typedef struct _WebKitDOMNode WebKitDOMNode;
typedef struct _WebKitDOMNodeClass WebKitDOMNodeClass;

typedef struct _WebKitDOMNodeFilter WebKitDOMNodeFilter;
typedef struct _WebKitDOMNodeFilterClass WebKitDOMNodeFilterClass;

typedef struct _WebKitDOMNodeIterator WebKitDOMNodeIterator;
typedef struct _WebKitDOMNodeIteratorClass WebKitDOMNodeIteratorClass;

typedef struct _WebKitDOMNodeList WebKitDOMNodeList;
typedef struct _WebKitDOMNodeListClass WebKitDOMNodeListClass;

typedef struct _WebKitDOMObject WebKitDOMObject;
typedef struct _WebKitDOMObjectClass WebKitDOMObjectClass;

typedef struct _WebKitDOMPerformance WebKitDOMPerformance;
typedef struct _WebKitDOMPerformanceClass WebKitDOMPerformanceClass;

typedef struct _WebKitDOMPerformanceEntry WebKitDOMPerformanceEntry;
typedef struct _WebKitDOMPerformanceEntryClass WebKitDOMPerformanceEntryClass;

typedef struct _WebKitDOMPerformanceEntryList WebKitDOMPerformanceEntryList;
typedef struct _WebKitDOMPerformanceEntryListClass WebKitDOMPerformanceEntryListClass;

typedef struct _WebKitDOMPerformanceNavigation WebKitDOMPerformanceNavigation;
typedef struct _WebKitDOMPerformanceNavigationClass WebKitDOMPerformanceNavigationClass;

typedef struct _WebKitDOMPerformanceTiming WebKitDOMPerformanceTiming;
typedef struct _WebKitDOMPerformanceTimingClass WebKitDOMPerformanceTimingClass;

typedef struct _WebKitDOMProcessingInstruction WebKitDOMProcessingInstruction;
typedef struct _WebKitDOMProcessingInstructionClass WebKitDOMProcessingInstructionClass;

typedef struct _WebKitDOMRange WebKitDOMRange;
typedef struct _WebKitDOMRangeClass WebKitDOMRangeClass;

typedef struct _WebKitDOMScreen WebKitDOMScreen;
typedef struct _WebKitDOMScreenClass WebKitDOMScreenClass;

typedef struct _WebKitDOMShadowRoot WebKitDOMShadowRoot;
typedef struct _WebKitDOMShadowRootClass WebKitDOMShadowRootClass;

typedef struct _WebKitDOMStorage WebKitDOMStorage;
typedef struct _WebKitDOMStorageClass WebKitDOMStorageClass;

typedef struct _WebKitDOMStorageInfo WebKitDOMStorageInfo;
typedef struct _WebKitDOMStorageInfoClass WebKitDOMStorageInfoClass;

typedef struct _WebKitDOMStorageQuota WebKitDOMStorageQuota;
typedef struct _WebKitDOMStorageQuotaClass WebKitDOMStorageQuotaClass;

typedef struct _WebKitDOMStyleMedia WebKitDOMStyleMedia;
typedef struct _WebKitDOMStyleMediaClass WebKitDOMStyleMediaClass;

typedef struct _WebKitDOMStyleSheet WebKitDOMStyleSheet;
typedef struct _WebKitDOMStyleSheetClass WebKitDOMStyleSheetClass;

typedef struct _WebKitDOMStyleSheetList WebKitDOMStyleSheetList;
typedef struct _WebKitDOMStyleSheetListClass WebKitDOMStyleSheetListClass;

typedef struct _WebKitDOMText WebKitDOMText;
typedef struct _WebKitDOMTextClass WebKitDOMTextClass;

typedef struct _WebKitDOMTextTrack WebKitDOMTextTrack;
typedef struct _WebKitDOMTextTrackClass WebKitDOMTextTrackClass;

typedef struct _WebKitDOMTextTrackCue WebKitDOMTextTrackCue;
typedef struct _WebKitDOMTextTrackCueClass WebKitDOMTextTrackCueClass;

typedef struct _WebKitDOMTextTrackCueList WebKitDOMTextTrackCueList;
typedef struct _WebKitDOMTextTrackCueListClass WebKitDOMTextTrackCueListClass;

typedef struct _WebKitDOMTextTrackList WebKitDOMTextTrackList;
typedef struct _WebKitDOMTextTrackListClass WebKitDOMTextTrackListClass;

typedef struct _WebKitDOMTimeRanges WebKitDOMTimeRanges;
typedef struct _WebKitDOMTimeRangesClass WebKitDOMTimeRangesClass;

typedef struct _WebKitDOMTouch WebKitDOMTouch;
typedef struct _WebKitDOMTouchClass WebKitDOMTouchClass;

typedef struct _WebKitDOMTrackEvent WebKitDOMTrackEvent;
typedef struct _WebKitDOMTrackEventClass WebKitDOMTrackEventClass;

typedef struct _WebKitDOMTreeWalker WebKitDOMTreeWalker;
typedef struct _WebKitDOMTreeWalkerClass WebKitDOMTreeWalkerClass;

typedef struct _WebKitDOMUIEvent WebKitDOMUIEvent;
typedef struct _WebKitDOMUIEventClass WebKitDOMUIEventClass;

typedef struct _WebKitDOMValidityState WebKitDOMValidityState;
typedef struct _WebKitDOMValidityStateClass WebKitDOMValidityStateClass;

typedef struct _WebKitDOMVideoPlaybackQuality WebKitDOMVideoPlaybackQuality;
typedef struct _WebKitDOMVideoPlaybackQualityClass WebKitDOMVideoPlaybackQualityClass;

typedef struct _WebKitDOMVideoTrack WebKitDOMVideoTrack;
typedef struct _WebKitDOMVideoTrackClass WebKitDOMVideoTrackClass;

typedef struct _WebKitDOMVideoTrackList WebKitDOMVideoTrackList;
typedef struct _WebKitDOMVideoTrackListClass WebKitDOMVideoTrackListClass;

typedef struct _WebKitDOMWebKitNamedFlow WebKitDOMWebKitNamedFlow;
typedef struct _WebKitDOMWebKitNamedFlowClass WebKitDOMWebKitNamedFlowClass;

typedef struct _WebKitDOMWebKitPoint WebKitDOMWebKitPoint;
typedef struct _WebKitDOMWebKitPointClass WebKitDOMWebKitPointClass;

typedef struct _WebKitDOMWheelEvent WebKitDOMWheelEvent;
typedef struct _WebKitDOMWheelEventClass WebKitDOMWheelEventClass;

typedef struct _WebKitDOMXPathExpression WebKitDOMXPathExpression;
typedef struct _WebKitDOMXPathExpressionClass WebKitDOMXPathExpressionClass;

typedef struct _WebKitDOMXPathNSResolver WebKitDOMXPathNSResolver;
typedef struct _WebKitDOMXPathNSResolverClass WebKitDOMXPathNSResolverClass;

typedef struct _WebKitDOMXPathResult WebKitDOMXPathResult;
typedef struct _WebKitDOMXPathResultClass WebKitDOMXPathResultClass;


#endif
