
Pod::Spec.new do |spec|

  spec.name         = "SLContractSDK_FX"
  spec.version      = "0.0.2"
  spec.summary      = "合约交易" # 简介
  spec.description  = "合约交易（不包含界面）"   # 描述

  spec.homepage     = "https://github.com/wwly/SLContractSDK_FX"
  spec.license      = { :type => 'MIT', :file => 'LICENSE' }
  spec.author       = { "wwly" => "wwlyvip@163.com" }
  spec.source       = { :git => 'https://github.com/wwly/SLContractSDK_FX.git', :tag => spec.version.to_s }

  spec.vendored_frameworks = "SLContractSDK.framework"

  spec.ios.deployment_target = '8.0'

  spec.dependency 'AFNetworking', '~> 3.2.1'
  spec.dependency 'MJExtension'
  spec.dependency 'SocketRocket'

end


