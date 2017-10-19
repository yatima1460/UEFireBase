package com.epicgames.ue4;

import com.google.firebase.quickstart.auth.OBBDownloaderService;
import com.google.firebase.quickstart.auth.DownloaderActivity;


public class DownloadShim
{
	public static OBBDownloaderService DownloaderService;
	public static DownloaderActivity DownloadActivity;
	public static Class<DownloaderActivity> GetDownloaderType() { return DownloaderActivity.class; }
}

