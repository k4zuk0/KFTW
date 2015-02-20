<?hh

namespace KFTW\App;

use KFTW\Routing\Router;
use KFTW\Bundle\Bundle;
use KFTW\Http\Request;

abstract class App {
    protected Router $router;
    protected array<Bundle> $bundles;
    protected bool $loaded;
    
    final public function __construct(
        protected Request $request
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
                $bundleExplodedFQCN = explode('\\', get_class($bundle));
                array_pop($bundleExplodedFQCN);
                $namespace = implode('\\', $bundleExplodedFQCN);
                $this->router->addRoute($routeName, [
                    $namespace.'\Controller\\'.$controllerInfos[0].'Controller',
                    $controllerInfos[1].'Action'
                ]);
            }
        }
        
        if (($route = (string)$this->request->get('route'))) {
            $controllerInfos = $this->router->getRoute($route);
            if ($controllerInfos) {
                $controllerClass = '\\'.$controllerInfos[0];
                $controller = new $controllerClass();
                
                $return = $controller->$controllerInfos[1]();
                
                echo 'Matching route returned :'."\n";
                var_dump($return);
            } else
                echo 'The given route "'.$route.'" did not match any known route'."\n";
        } else
            echo 'No route given'."\n";
        
        $this->loaded = true;
    }
    
    abstract public function listBundles();
    
    public function getRouter() : Router {
        return $this->router;
    }
}