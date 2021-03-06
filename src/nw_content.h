#ifndef NWJS_CONTENT_HOOKS_H
#define NWJS_CONTENT_HOOKS_H

#include "nw_package.h"
#include "third_party/WebKit/public/web/WebNavigationPolicy.h"

namespace base {
  class DictionaryValue;
}

namespace blink {
  class WebFrame;
  class WebLocalFrame;
  class WebURLRequest;
  class WebString;
}

namespace content {
  class RenderProcessHost;
  class NotificationDetails;
  class RenderView;
  class WebContents;
}

namespace extensions {
  class Extension;
  class ScriptContext;
  class Dispatcher;
  class AppWindow;
}

namespace nw {
int MainPartsPreCreateThreadsHook();
void MainPartsPostDestroyThreadsHook();
void ContextCreationHook(blink::WebLocalFrame* frame, extensions::ScriptContext* context);
void LoadNWAppAsExtensionHook(base::DictionaryValue* manifest, std::string* error);
void DocumentElementHook(blink::WebFrame* frame,
                         const extensions::Extension* extension,
                         const GURL& effective_document_url);
void DocumentFinishHook(blink::WebFrame* frame,
                         const extensions::Extension* extension,
                         const GURL& effective_document_url);
 void RendererProcessTerminatedHook(content::RenderProcessHost* process,
                                    const content::NotificationDetails& details);
 void OnRenderProcessShutdownHook(extensions::ScriptContext* context);
 void willHandleNavigationPolicy(content::RenderView* rv,
                                 blink::WebFrame* frame,
                                 const blink::WebURLRequest& request,
                                 blink::WebNavigationPolicy* policy,
                                 blink::WebString* manifest,
                                 bool new_win);
 void ExtensionDispatcherCreated(extensions::Dispatcher* dispatcher);
 void CalcNewWinParams(content::WebContents* new_contents, void* params,
                       std::string* nw_inject_js_doc_start,
                       std::string* nw_inject_js_doc_end);

}

#endif
