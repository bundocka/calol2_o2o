import FWCore.ParameterSet.Config as cms

process = cms.Process("tester")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cout.placeholder = cms.untracked.bool(False)
process.MessageLogger.cout.threshold = cms.untracked.string('DEBUG')
process.MessageLogger.debugModules = cms.untracked.vstring('*')

process.source = cms.Source("EmptySource", firstRun = cms.untracked.uint32(254894)) #91
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) )

# The line below sets configuration from local file
process.load('L1Trigger.L1TMuonOverlap.fakeOmtfParams_cff')

# Last option is readin local sqlite file
from CondCore.DBCommon.CondDBSetup_cfi import CondDBSetup
process.l1conddb = cms.ESSource("PoolDBESSource",
       CondDBSetup,
       connect = cms.string('sqlite:qwe.db'),
       toGet   = cms.VPSet(
            cms.PSet(
                 record = cms.string('L1TMuonOverlapPatternParamsRcd'),
                 tag = cms.string("dummy")
            )
       )
)

process.l1or = cms.EDAnalyzer("L1TOverlapReader")

process.p = cms.Path(process.l1or)

