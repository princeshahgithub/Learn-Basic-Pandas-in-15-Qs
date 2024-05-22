public class Solution {
    public int[] ShortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        int[] shortPath = new int[n];
            var redCityMap = new Dictionary<int, List<int>>();
            var blueCityMap = new Dictionary<int, List<int>>();

            foreach (var val in redEdges){
                if (redCityMap.ContainsKey(val[0])){
                    redCityMap[val[0]].Add(val[1]);
                }
                else{
                    redCityMap.Add(val[0], new List<int>() {val[1]});
                }
            }
            foreach (var val in blueEdges){
                if (blueCityMap.ContainsKey(val[0])){
                    blueCityMap[val[0]].Add(val[1]);
                }
                else{
                    blueCityMap.Add(val[0], new List<int>() {val[1]});
                }
            }
            var VistedNodes = new List<(int number, bool redsTurn, int distance)> { (0,true, 0), (0, false, 0) };
            var ColorChangeNodes = new List<(int number, bool redsTurn, int distance)>();
            while (VistedNodes.Count != 0)
            {
                var currNode = VistedNodes[0];
                var nodes = currNode.redsTurn && redCityMap.ContainsKey(currNode.number) ? redCityMap[currNode.number] :
                    (!currNode.redsTurn && blueCityMap.ContainsKey(currNode.number) ? blueCityMap[currNode.number] : new List<int>());
                foreach (var node in nodes)
                {
                    (int number, bool redsTurn, int distance) node2 = (node, !currNode.redsTurn, currNode.distance + 1);
                    if (node2.number!=0 && (node2.distance < shortPath[node2.number] || shortPath[node2.number] == 0)){
                        shortPath[node2.number] = node2.distance;
                    }
                    if (!ColorChangeNodes.Any(d=>d.number == node2.number && d.redsTurn == node2.redsTurn)){
                        VistedNodes.Add(node2);
                    }
                }
                VistedNodes.RemoveAt(0);
                ColorChangeNodes.Add(currNode);
            }

            for(int i=1;i<shortPath.Length;i++){
                if (shortPath[i] == 0){
                    shortPath[i] = -1;
                }
            }
            return shortPath;
    }
}