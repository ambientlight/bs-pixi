import webpack from 'webpack'
import path from 'path'
import TerserPlugin from 'terser-webpack-plugin';
import CopyWebpackPlugin from 'copy-webpack-plugin'
import HTMLWebpackPlugin from 'html-webpack-plugin'
import { BundleAnalyzerPlugin } from 'webpack-bundle-analyzer'
import { getIfUtils, removeEmpty } from 'webpack-config-utils'

const config = (env, ifProduction, ifNotProduction) => ({
  	entry: {
    	main: [
			'./lib/js/src/Index.bs.js',
    	]
 	},
  	output: {
		filename: "[name].bundle.js",
		path: path.resolve(__dirname, 'dist'),
		publicPath: '/'
	},

	mode: ifProduction('production', 'development'),
	devtool: 'none',
	devServer: {
		port: 8080,
		clientLogLevel: 'info',
		publicPath: '/',
		historyApiFallback: true
	},
	
	resolve: {
		alias: {
			reason: path.resolve(__dirname, "lib/js/src"),
			src: path.resolve(__dirname, "src"),
			assets: path.resolve(__dirname, "assets"),
			'react-dom': '@hot-loader/react-dom'
		},
		extensions: [".js", ".jsx", ".json"]
	},
	
	module: {
		// noParse: [/aws/],
		rules: [{
			exclude: /node_modules/, // don't transpile node_modules
			test: /\.(js|jsx)$/,     // do transpile any files ending in .jsx
			use: {
				loader: 'babel-loader',
			}
		},
		{ test: /\.css$/, loaders: ['style-loader', 'css-loader']},
		{ test: /\.(woff|woff2|eot|ttf|otf|svg|png)$/, use: { 
			loader: 'url-loader', 
			options: {
				limit: 8192,
				fallback: 'file-loader'
			}
		}}]
	},
	plugins: removeEmpty([
		new webpack.DefinePlugin({
			'process.env.NODE_ENV': JSON.stringify(env.production ? 'production' : 'development'),
			ENVIRONMENT: JSON.stringify({
				isDev: !env.production,
				shouldHotReloadEpics: env.hotEpics !== undefined,
				signInRequired: false
			})
		}),
		
		new HTMLWebpackPlugin({
			//hash: true,
			excludeChunks: [],
			template: './base.html'
		}),
		
		new webpack.NamedModulesPlugin(),

		new CopyWebpackPlugin([
			// amr codecs, lazy-loaded for arm playback used in gt-card-files
			// { from: './assets/favicon', to: './' },
			// copy version file to deployment root
		]),

    	env.analyze ? new BundleAnalyzerPlugin() : undefined
	]),

	// Webpack 4 has default optimization plugin entry,
	// modify settings here
	optimization: {
		minimizer: [
			new TerserPlugin({
				cache: true,
				parallel: true,
				// sourceMap: true, // XXX: Enable me if needed
				terserOptions: {
					safari10: true,
					mangle: true,
					output: {
						comments: false,
						beautify: false
					},
				}
			})
		]
	}
})

const envextract = config => env => {
	const { ifProduction, ifNotProduction } = getIfUtils(env)
	return config(env, ifProduction, ifNotProduction)
}

export default envextract(config)