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
            foreach ($bundle->getRoutes() as $routeName => $controllerInfos) {
                $bundleExplodedFQCN = explode('\\', get_class($bundleExplodedFQCN));
                array_pop($bundleExplodedFQCN);
                $namespace = implode('\\', $bundleExplodedFQCN);
                $this->router->addRoute($routeName, [
                    $namespace.'\Controller\\'.$controllerInfos[0].'Controller',
                    $controllerInfos[1].'Action'
                ]);
            }
        }
        
        $this->loaded = true;
    }
    
    abstract public function listBundles();
    
    public function getRouter() : Router {
        return $this->router;
    }
}