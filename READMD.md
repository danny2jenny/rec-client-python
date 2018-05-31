# Introduction

This is a CCTV camera client for windows.

The management system is web-based. But web has poor support for live video.

So I use cefPython framework with wxPython. Python can communication with web through cefPython. Then wxPython for live video work, and Web for management interface.

App includes how to call hikvision SDK、dahuatech SDK from web. Web just provide video config information and call Python to invoke SDK to show video.