/*
---
description: Dijkstra's algorithm, conceived by computer scientist Edsger Dijkstra, is a graph search algorithm that solves in single-source shortest path problem for a graph with non-negative edge path costs, producing a shortest path tree.

authors:
- Adrian Statescu (http://thinkphp.ro)

license:
- MIT-style license

requires:
 core/1.5.1: '*'

provides: Dijkstra
...
*/

var Dijkstra=new Class({PInfinit:888,output:[],start:1,end:3,initialize:function(start_point,end_point,r){this.nodes=function(r){var vec=[];for(var i=0;i<r.length;i++)for(var j=0;j<2;j++)vec.push(road[i][j]);function max(a,b){if(a>b)return a;else return b}function maxN(li,ls){if(li==ls)return vec[li];else m=parseInt((li+ls)/2);return max(maxN(li,m),maxN(m+1,ls))}return maxN(0,vec.length-1)}(r);this.start=start_point,this.end=end_point;var createMatrix=function(rows,columns){var mat=new Array(rows);
for(var i=0;i<rows;i++)mat[i]=new Array(columns);return mat};var createArray=function(n){var arr=new Array(n);for(var i=0;i<arr.length;i++)arr[i]=0;return arr};this.matrix=r,this.Road=createMatrix(this.nodes+1,this.nodes+1);this.R=createArray(this.nodes+1);this.F=createArray(this.nodes+1);this.S=createArray(this.nodes+1);this._read();this._solve()},_read:function(){var n=this.matrix.length,x,y,cost;for(var i=1;i<=this.nodes;i++)for(var j=1;j<=this.nodes;j++)if(i==j)this.Road[i][j]=0;else this.Road[i][j]=
this.PInfinit;for(var i=0;i<n;i++){x=this.matrix[i][0];y=this.matrix[i][1];cost=this.matrix[i][2];this.Road[x][y]=cost}},_solve:function(){var min,posMin;this.S[this.start]=1;for(var i=1;i<=this.nodes;i++){this.R[i]=this.Road[this.start][i];if(this.start!=i)if(this.R[i]<this.PInfinit)this.F[i]=this.start}for(var i=1;i<=this.nodes-1;i++){min=this.PInfinit;for(var k=1;k<=this.nodes;k++)if(this.S[k]==0)if(this.R[k]<min){min=this.R[k];posMin=k}this.S[posMin]=1;for(var j=1;j<=this.nodes;j++)if(this.S[j]==
0)if(this.R[j]>this.R[posMin]+this.Road[posMin][j]){this.R[j]=this.R[posMin]+this.Road[posMin][j];this.F[j]=posMin}}},getCost:function(){return this.R[this.end]},getShortestPath:function(){this.getRoad(this.end);return this.output},getRoad:function(node){if(this.F[node])this.getRoad(this.F[node]);this.output.push(node)}});