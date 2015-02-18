<?hh

namespace KFTW\App;

use KFTW\Routing\Router;
use KFTW\Bundle\Bundle;

abstract class App {
    protected Router $router;
    protected array<Bundle> $bundles;
    protected bool $loaded;
    
    final public function __construct(
    ) {
        $this->router = new Router();
        $this->bundles = [];
        $this->loaded = false;
    }
    
    public function load() {
        if ($this->loaded)
            return;
        
        $this->bundles = $this->listBundles();
        foreach ($this->bundles as $bundle) {
            $this->router->addRoutes($bundle->getRoutes());
        }
        
        $this->loaded = true;
    }
    
    abstract public function listBundles();
    
    public function getRouter() : Router {
        return $this->router;
    }
}