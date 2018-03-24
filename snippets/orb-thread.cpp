// ORB extraction
thread threadLeft (&Frame::ExtractORB, this, 0, imLeft );
thread threadRight(&Frame::ExtractORB, this, 1, imRight);
threadLeft.join();
threadRight.join();

void Frame::ExtractORB(int flag, const cv::Mat &im) {
    if(flag==0)
        (*mpORBextractorLeft)(im,cv::Mat(),mvKeys,mDescriptors);
    else
        (*mpORBextractorRight)(im,cv::Mat(),mvKeysRight,mDescriptorsRight);
}

// Feature extractor. The right is used only in the stereo case.
ORBextractor* mpORBextractorLeft, *mpORBextractorRight;

// http://en.cppreference.com/w/cpp/utility/functional/ref
// calc homograpy   matrix & scoring
thread threadH(&Initializer::FindHomography,this,ref(vbMatchesInliersH), ref(SH), ref(H));
// calc fundamental matrix & scoring
thread threadF(&Initializer::FindFundamental,this,ref(vbMatchesInliersF), ref(SF), ref(F));
threadH.join();
threadF.join();
float RH = SH/(SH+SF);
if(RH>0.40)
    return ReconstructH(vbMatchesInliersH,H,mK,R21,t21,vP3D,vbTriangulated,1.0,50);
else //if(pF_HF>0.6)
    return ReconstructF(vbMatchesInliersF,F,mK,R21,t21,vP3D,vbTriangulated,1.0,50);
