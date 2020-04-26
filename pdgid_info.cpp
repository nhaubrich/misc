void pdgid_info(){

    //File contains W->mu nu or e nu 
    TFile* f = new TFile("/eos/cms/store/group/phys_higgs/hbb/ntuples/VHbbPostNano/2017/V11/WplusH_HToBB_WToLNu_M125_13TeV_powheg_pythia8/adewit-crab_nano2017_WplusH_HT82/190606_065948/0000/tree_1.root");

    TTree *Events = (TTree*) f->Get("Events");
    std::cout << Events->GetEntries() << std::endl;


    unsigned int nGenPart;
    unsigned int max_nGenPart = 200;
    int GenPart_pdgId[max_nGenPart];
    int GenPart_genPartIdxMother[max_nGenPart];
    
    unsigned int nMuon;
    unsigned int max_nMuon = 10;
    int Muon_genPartIdx[max_nMuon];

    int nEvents = Events->GetEntries();

    

    Events->SetBranchAddress("nGenPart",&nGenPart);
    Events->SetBranchAddress("GenPart_pdgId",&GenPart_pdgId);
    Events->SetBranchAddress("GenPart_genPartIdxMother",&GenPart_genPartIdxMother);

    Events->SetBranchAddress("nMuon",&nMuon);
    Events->SetBranchAddress("Muon_genPartIdx",&Muon_genPartIdx);


    for(int j=0;j<nEvents;j++){
        Events->GetEntry(j);
        std::cout << "\nnMuon\t" <<nMuon << std::endl;
        for(int i=0; i<nMuon; i++){
            int genMuonIdx = Muon_genPartIdx[i];
            std::cout << "genMuonIdx\t" << genMuonIdx << std::endl;
            if(genMuonIdx>-1){
                std::cout << "Matched muon pdgid\t" << GenPart_pdgId[genMuonIdx] << std::endl;
                int motherGenMuonIdx = GenPart_genPartIdxMother[genMuonIdx];
                std::cout << "pdgId of mother of gen muon\t" << GenPart_pdgId[motherGenMuonIdx] << std::endl;
            }
        }
    }
}
