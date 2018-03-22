$bootstrap=<<SCRIPT
apt-get update
apt-get -y install vim
apt-get -y install g++
apt-get -y install libglib2.0-dev
SCRIPT

Vagrant.configure("2") do |config|
	config.vm.box = "ubuntu/trusty64"
	config.vm.network "public_network", ip: "192.168.33.10"
	config.vm.provider "virutalbox" do |vb|
		vb.customize ["modifyvm", :id, "--memory", "4024"]
	end
	config.vm.provision :shell, inline: $bootstrap
	config.vm.provision "file", source: ".", destination: "."
end
