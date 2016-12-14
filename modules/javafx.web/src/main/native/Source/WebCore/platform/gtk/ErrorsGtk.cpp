/*
 * Copyright (C) 2011 Igalia S.L.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "config.h"
#include "ErrorsGtk.h"

#include "ResourceError.h"
#include "ResourceRequest.h"
#include "ResourceResponse.h"
#include <glib/gi18n-lib.h>

namespace WebCore {

ResourceError cancelledError(const ResourceRequest& request)
{
    return ResourceError(errorDomainNetwork, NetworkErrorCancelled, request.url(), _("Load request cancelled"));
}

ResourceError blockedError(const ResourceRequest& request)
{
    return ResourceError(errorDomainPolicy, PolicyErrorCannotUseRestrictedPort, request.url(), _("Not allowed to use restricted network port"));
}

ResourceError blockedByContentBlockerError(const ResourceRequest& request)
{
    return ResourceError(errorDomainPolicy, PolicyErrorBlockedByContentBlocker, request.url(), _("Blocked by content blocker"));
}

ResourceError cannotShowURLError(const ResourceRequest& request)
{
    return ResourceError(errorDomainPolicy, PolicyErrorCannotShowURL, request.url(), _("URL cannot be shown"));
}

ResourceError interruptedForPolicyChangeError(const ResourceRequest& request)
{
    return ResourceError(errorDomainPolicy, PolicyErrorFrameLoadInterruptedByPolicyChange, request.url(), _("Frame load was interrupted"));
}

ResourceError cannotShowMIMETypeError(const ResourceResponse& response)
{
    return ResourceError(errorDomainPolicy, PolicyErrorCannotShowMimeType, response.url(), _("Content with the specified MIME type cannot be shown"));
}

ResourceError fileDoesNotExistError(const ResourceResponse& response)
{
    return ResourceError(errorDomainNetwork, NetworkErrorFileDoesNotExist, response.url(), _("File does not exist"));
}

ResourceError pluginWillHandleLoadError(const ResourceResponse& response)
{
    return ResourceError(errorDomainPlugin, PluginErrorWillHandleLoad, response.url(), _("Plugin will handle load"));
}

ResourceError downloadNetworkError(const ResourceError& networkError)
{
    return ResourceError(errorDomainDownload, DownloadErrorNetwork, networkError.failingURL(), networkError.localizedDescription());
}

ResourceError downloadCancelledByUserError(const ResourceResponse& response)
{
    return ResourceError(errorDomainDownload, DownloadErrorCancelledByUser, response.url(), _("User cancelled the download"));
}

ResourceError downloadDestinationError(const ResourceResponse& response, const String& errorMessage)
{
    return ResourceError(errorDomainDownload, DownloadErrorDestination, response.url(), errorMessage);
}

ResourceError printError(const URL& failingURL, const String& errorMessage)
{
    return ResourceError(errorDomainPrint, PrintErrorGeneral, failingURL, errorMessage);
}

ResourceError printerNotFoundError(const URL& failingURL)
{
    return ResourceError(errorDomainPrint, PrintErrorPrinterNotFound, failingURL, _("Printer not found"));
}

ResourceError invalidPageRangeToPrint(const URL& failingURL)
{
    return ResourceError(errorDomainPrint, PrintErrorInvalidPageRange, failingURL, _("Invalid page range"));
}

} // namespace WebCore
